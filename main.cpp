#include <stack>
#include <iostream>
#include <vector>
#include <assert.h>
#include <SFML/Graphics.hpp>
#include "src/command.h"
#include "src/game.h"
#include "src/place_command.h"

/**
 Schrijf een Tic-Tac-Toe (3-op-een-rij) spelletje.
 Maak hiertoe een object voor het spel en een object voor een zet (command pattern).
 Sla het verloop van het spel op in een STL container.
 Implementeer een ‘undo’ feature door het her-afspelen van de gedane zetten behalve de laatste.
 Biedt, met zo min mogelijk code duplicatie, zowel een grafische (SFML) interface als een tekst-only interface.
 */

#define GRAPHICAL 1

int main() {
    game g;

    g.run();
    if (GRAPHICAL == 0) {
        std::string decision;
        g.print_board();
        std::cout << "Do a move by typing the position like (0,1) \n type undo to undo your turn0";
        while (g.is_running()) {
            std::cout << "it's player " << g.get_turn() << " his turn\n";
            std::cin >> decision;
            if (decision == "undo") {
                g.undo();
            } else {
                g.place(new place_command(g, decision[0] - 48, decision[1] - 48));
            }
            g.print_board();
        }
    } else {
        auto const grid_size = 100;
        sf::Texture X, O, BG;
        if (!X.loadFromFile("assets/x.png") || !O.loadFromFile("assets/o.png") ||
            !BG.loadFromFile("assets/bg.jpg")) { return -1; }
        sf::Sprite bg_sprite;
        bg_sprite.setTexture(BG);
        sf::RenderWindow window(sf::VideoMode(grid_size * 3, grid_size * 3), "Game", sf::Style::Default | sf::Style::Close);
        while (window.isOpen()) {
            sf::Event e;
            while (window.pollEvent(e)) {
                if ((e.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    || e.type == sf::Event::Closed
                        ) {
                    window.close();
                } else if (e.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left)&& g.is_running()) {
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                    g.place(new place_command(g, mousePosition.x / grid_size, mousePosition.y / grid_size));
                } else if (e.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Right)&& g.is_running()) {
                    g.undo();
                } else if (e.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
                    g.run();
                }

            }
            window.clear();
            window.draw(bg_sprite);
            for (int i = 0; i < g.get_board().size(); i++) {
                for (int j = 0; j < g.get_board().size(); j++) {
                    sf::Sprite sprite;
                    if (g.get_board()[i][j] == 1) {
                        sprite.setTexture(X);
                    } else if (g.get_board()[i][j] == 2) {
                        sprite.setTexture(O);
                    }
                    sprite.setPosition(i * grid_size, j * grid_size);
                    window.draw(sprite);
                }
            }
            window.display();
        }
    }


    return EXIT_SUCCESS;
}