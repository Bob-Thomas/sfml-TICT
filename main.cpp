#include<SFML/Graphics.hpp>
#include <fstream>
#include"src/ball.h"
#include "src/action.h"
#include "src/draggable_square.h"
#include "src/draggable_line.h"
#include "src/draggable_photo.h"
#include "src/exceptions.h"

sf::Vector2f Vector2f_from_Vector2i(sf::Vector2i vector2);

/**
 * 18.3. Week 3 : Factory
Maak een klasse hierargie van beweegbare scherm objecten. Handel het selecteren en bewegen af in de superklasse.

Maak een factory function die scherm objecten creeert: circle, rectangle, line, picture. Ieder object heeft een positie, en behalve picture ook nog een kleur, circle heeft een diameter, en line en rectange een tweede punt (positie is het eerste punt). Check alle fouten die kunnen optreden en genereer daarvoor passende exceptions. Let ook op einde-file.

Maak een applicatie die
De objecten lees uit een text file en toont,
Je de gelegenheid biedt ze te slecteren en te verschuiven,
Bij het afsluiten de textfile overschrijft met de nieuwe lijst van objecten.

Sla de (pointers naar) de objecten op in een container waar je tijdens het afbeelden en afhandeklen van gebruikershandelingen met een for( : ) loop doorheen loopt.

Let op wat je doet als er een fout wordt geconstateerd in de textfile. Zorg er in ieder geval voor dat de gebruiker duidelijk te zien krijgt wat de fout is, en dat de textfile niet overschreven wordt.


(50,60) CIRCLE blue 10
(10,10) RECTANGLE red (30,40)
(110, 50) PICTURE bird.jpg

 */

std::ifstream &operator>>(std::ifstream &input, sf::Vector2f &rhs) {
    char c;
    if (!(input >> c)) { throw end_of_file(); }
    if (c != '(') { throw invalid_position(c); }

    if (!(input >> rhs.x)) {
        throw invalid_position(c);
    }

    if (!(input >> c)) {
        throw (invalid_character(c));
    }
    if (!(input >> rhs.y)) {
        throw (invalid_position(c));
    }

    if (!(input >> c)) {
        throw (invalid_character(c));
    }
    if (c != ')') { throw invalid_position(c); }

    return input;
}

std::ifstream &operator>>(std::ifstream &input, sf::Color &rhs) {
    std::string s;
    input >> s;
    for (auto const &color : colors) {
        if (color.name == s) {
            rhs = color.color;
            return input;
        }
    }
    if (s == "") {
        throw end_of_file();
    }
    throw unknown_color(s);
}

entity *screen_object_read(std::ifstream &input) {
    sf::Vector2f position;
    std::string name;
    input >> position >> name;

    if (name == "CIRCLE") {
        int radius;
        sf::Color color;
        input >> color;
        input >> radius;
        return new ball(position, {0, 0}, color, radius);

    }
    else if (name == "LINE") {
        sf::Color color;
        input >> color;
        return new draggable_line(position, color);
    }
    else if (name == "RECTANGLE") {
        sf::Vector2f size;
        sf::Color color;
        input >> color;
        input >> size;
        return new draggable_square(position, size, color);

    } else if (name == "PICTURE") {
        std::string src;
        input >> src;
        src = src;
        return new draggable_photo(src, position, {1, 1});

    } else if (name == "") {
        throw end_of_file();
    }

    throw unknown_shape(name);
}

int main() {

    sf::RenderWindow window{sf::VideoMode{1920, 1080}, "Game"};
    std::string file("./assets/config/objects.magic");

    sf::Event event;

    std::vector<entity *> entities = std::vector<entity *>();

    {
        std::ifstream input(file);
        if (!input.good()) {
            throw (unknown_file(file));
        }
        try {
            for (; ;) {
                entities.push_back(screen_object_read(input));
            }
        } catch (end_of_file) {
            std::cout << "\nEOF\n";
            // do nothing
        } catch (std::exception &problem) {
            std::cout << problem.what();
        }
        input.close();
    }

    sf::Clock clock;
    sf::Time elapsed = clock.restart();

    //60 FPS master race
    const sf::Time update_ms = sf::seconds(1.f / 60.f);

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                std::ofstream output("./assets/config/objects.magic");
                for (entity *e : entities) {
                    e->write(output);
                    output << "\n";
                }
                output.close();
                window.close();
            }
            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Right) {
                bool test = false;
                entity *teste;
                for(entity *e : entities) {
                    if (e->getBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                        test = true;
                        teste = e;
                        break;
                    }
                }
                if(test)
                    entities.erase(std::remove(entities.begin(), entities.end(), teste), entities.end());
                else
                    entities.push_back(new ball(sf::Vector2f(event.mouseButton.x, event.mouseButton.y), {0, 0}, sf::Color::Red,30));

            }
            for (entity *e: entities) {
                e->input(event);
            }
        }
        elapsed += clock.restart();
        while (elapsed >= update_ms) {
            float delta = update_ms.asSeconds();
            for (entity *e: entities) {
                e->update(delta);
            }

            elapsed -= update_ms;
        }
        window.clear();
        for (entity *e : entities) {
            e->draw(window);
        }
        window.display();
    }

    return EXIT_SUCCESS;
}