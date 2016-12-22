//
// Created by endargon on 12/9/16.
//

#ifndef SFML_DEMO_DRAGGABLE_SQUARE_H
#define SFML_DEMO_DRAGGABLE_SQUARE_H

#include <SFML/Graphics.hpp>
#include "selectable.h"
#include "colors.h"
#include <fstream>

class draggable_square : public selectable {
        sf::RectangleShape shape;
        sf::Vector2f position;
        sf::Color color;
    public:
        draggable_square(sf::Vector2f position, sf::Vector2f size, sf::Color color);

        void draw(sf::RenderWindow &w) const {
            w.draw(shape);
        };

        void write(std::ofstream &s);

        void move(sf::Vector2f position);

        sf::FloatRect getBounds() const;;

        sf::Vector2f getPosition() const;


};

#endif //SFML_DEMO_DRAGGABLE_SQUARE_H
