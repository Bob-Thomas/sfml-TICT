#include<SFML/Graphics.hpp>
#include"src/ball.h"
#include "src/action.h"
#include "src/paddle.h"

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
 */

int main() {

    sf::RenderWindow window{sf::VideoMode{640, 480}, "Game"};

    ball my_ball({100, 100}, {0, 0}, sf::Color::Red);
    sf::Event event;

    selectable *drawables[] = {
            &my_ball
    };

    action actions[] = {
            action([&] {
                for (selectable *e : drawables) {
                    e->deselect();
                }
            }),
            action(
                    sf::Mouse::Left,
                    [&]{
                        for (selectable *e : drawables) {
                            e->select(Vector2f_from_Vector2i(sf::Mouse::getPosition()));
                        }
                    }
            ),
            action(
                    &event,
                    [&]{
                        for (selectable *e : drawables) {
                            if(e->is_selected()) {
                                e->drag(Vector2f_from_Vector2i(sf::Mouse::getPosition()));
                            }
                        }
                    }
            )

    };

    sf::Clock clock;
    sf::Time elapsed = clock.restart();

    //60 FPS master race
    const sf::Time update_ms = sf::seconds(1.f / 60.f);

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        elapsed += clock.restart();
        while (elapsed >= update_ms) {
            float delta = update_ms.asSeconds();
            for (auto &action : actions) {
                action();
            }
            elapsed -= update_ms;
        }
        window.clear();
        for (entity *e : drawables) {
            e->draw(window);
        }
        window.display();
    }

    return EXIT_SUCCESS;
}

sf::Vector2f Vector2f_from_Vector2i(sf::Vector2i rhs) {
    return sf::Vector2f(
            static_cast< float >( rhs.x ),
            static_cast< float >( rhs.y )
    );
}