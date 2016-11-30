//
// Created by endargon on 11/30/16.
//
#include "wall.h"
wall::wall(sf::Vector2f position, sf::Vector2f size, sf::Color color) {
    shape.setPosition(position);
    shape.setSize(size);
    shape.setFillColor(color);
}

wall::wall() : wall(sf::Vector2f(0.0, 0.0), sf::Vector2f(0.0, 0.0), sf::Color::Transparent) {}

void wall::draw(sf::RenderWindow &w) const {
    w.draw(shape);
}

sf::FloatRect wall::getBounds() const {
    return shape.getGlobalBounds();
}