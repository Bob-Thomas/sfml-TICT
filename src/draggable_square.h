//
// Created by endargon on 12/9/16.
//

#ifndef SFML_DEMO_DRAGGABLE_SQUARE_H
#define SFML_DEMO_DRAGGABLE_SQUARE_H

#include <SFML/Graphics.hpp>
#include "selectable.h"

class draggable_square :  public selectable {
    sf::RectangleShape shape;
    sf::Vector2f position;
public:
    draggable_square(sf::Vector2f position, sf::Vector2f size, sf::Color color){
        shape.setPosition(position);
        shape.setSize(size);
        shape.setFillColor(color);
    }

    void draw(sf::RenderWindow &w) const {
        w.draw(shape);
    };


    void move(sf::Vector2f position) {
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
