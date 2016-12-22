//
// Created by endargon on 12/9/16.
//

#ifndef SFML_DEMO_DRAGGABLE_LINE_H
#define SFML_DEMO_DRAGGABLE_LINE_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "selectable.h"
#include "colors.h"
#include <fstream>

struct colors;

class draggable_line : public selectable {
    sf::RectangleShape shape;
    sf::Vector2f position;
    sf::Color color;
public:
    draggable_line(sf::Vector2f start, sf::Color color) : position(start), color(color) {
        shape = sf::RectangleShape(start);
        shape.setFillColor(color);

    }

    void draw(sf::RenderWindow &w) const {
        w.draw(shape);
    };


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

    void write(std::ofstream &s) {
        s << "(" << position.x << "," << position.y << ") ";
        s << "LINE ";
        for (auto c : colors) {
            if (c.color == color) {
                s << c.name << " ";
                break;
            }
        }

    }

};

#endif //SFML_DEMO_DRAGGABLE_LINE_H
