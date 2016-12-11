//
// Created by endargon on 11/30/16.
//
#include "square.h"
square::square(sf::Vector2f position, sf::Vector2f size, sf::Color color) {
    shape.setPosition(position);
    shape.setSize(size);
    shape.setFillColor(color);
}

square::square() : square(sf::Vector2f(0.0, 0.0), sf::Vector2f(0.0, 0.0), sf::Color::Transparent) {}

void square::draw(sf::RenderWindow &w) const {
    w.draw(shape);
}

sf::FloatRect square::getBounds() const {
    return shape.getGlobalBounds();
}