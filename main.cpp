#include<SFML/Graphics.hpp>
#include"src/ball.h"
#include "src/action.h"
#include "src/paddle.h"
#include "src/draggable_square.h"
#include "src/draggable_line.h"
#include "src/draggable_photo.h"
#include "src/object_loader.h"

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

int main() {

    sf::RenderWindow window{sf::VideoMode{640, 480}, "Game"};

    ball my_ball({100, 100}, {800, 100}, sf::Color::Red);

    square walls[4];

    walls[0] = {sf::Vector2f(0.0, 0.0), sf::Vector2f(window.getSize().x, 20), sf::Color::Red}; //top
    walls[1] = {sf::Vector2f(window.getSize().x - 20, 0.0), sf::Vector2f(20.0, window.getSize().y),
                sf::Color::Red}; // right
    walls[2] = {sf::Vector2f(0.0, window.getSize().y - 20), sf::Vector2f(window.getSize().x, 20.0),
                sf::Color::Red}; //bottom
    walls[3] = {sf::Vector2f(0.0, 0.0), sf::Vector2f(20.0, window.getSize().y), sf::Color::Red}; //left

    draggable_square d_square(sf::Vector2f(200, 200), sf::Vector2f(200, 200), sf::Color::Red);
    draggable_line d_line(sf::Vector2f(30, 150), sf::Color::Blue);
    draggable_photo d_photo("./assets/images/bird.jpg", sf::Vector2f(30, 150), {0.25, 0.25});

    object_loader loader("./assets/config/saved.magic");

    loader.get_loaded_entities();

    sf::Event event;

    std::vector<entity*> entities = std::vector<entity*>();
    entities.push_back(&my_ball);
    entities.push_back(&walls[0]);
    entities.push_back(&walls[1]);
    entities.push_back(&walls[2]);
    entities.push_back(&walls[3]);
    entities.push_back(&d_square);
    entities.push_back(&d_line);
    entities.push_back(&d_photo);

    action actions[] = {
            action(my_ball, walls[0], [&] { my_ball.bounce(1); }),
            action(my_ball, walls[1], [&] { my_ball.bounce(-1); }),
            action(my_ball, walls[2], [&] { my_ball.bounce(1); }),
            action(my_ball, walls[3], [&] { my_ball.bounce(-1); })
    };

    sf::Clock clock;
    sf::Time elapsed = clock.restart();

    //60 FPS master race
    const sf::Time update_ms = sf::seconds(1.f / 60.f);

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            for(entity *e: entities) {
                e->input(event);
            }
        }
        elapsed += clock.restart();
        while (elapsed >= update_ms) {
            float delta = update_ms.asSeconds();
            for (auto &action : actions) {
                action();
            }
            for(entity* e: entities) {
                e->update(delta);
            }
            elapsed -= update_ms;
        }
        window.clear();
        for (entity* e : entities) {
            e->draw(window);
        }
        window.display();
    }

    return EXIT_SUCCESS;
}