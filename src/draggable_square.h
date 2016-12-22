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
    draggable_square(sf::Vector2f position, sf::Vector2f size, sf::Color color) : position(position), color(color) {
        shape.setPosition(position);
        shape.setSize(size);
        shape.setFillColor(color);
    }

    void draw(sf::RenderWindow &w) const {
        w.draw(shape);
    };

    void write(std::ofstream &s) {
        s << "(";
        s << position.x;
        s << ",";
        s << position.y;
        s << ") ";
        s << "RECTANGLE ";
        for (auto c : colors) {
            if (c.color == color) {
                s << c.name << " ";
                break;
            }
        }
        s << "(" << shape.getSize().x << "," << shape.getSize().y << ") ";

    }

    void move(sf::Vector2f position) {
        this->position = position;
        shape.setPosition(position);
    }

    sf::FloatRect getBounds() const {
        return shape.getGlobalBounds();
    };

    sf::Vector2f getPosition() const {
        return shape.getPosition();
    }


};

#endif //SFML_DEMO_DRAGGABLE_SQUARE_H
