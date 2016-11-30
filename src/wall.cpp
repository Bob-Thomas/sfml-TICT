//
// Created by endargon on 11/30/16.
//
#include "wall.h"
wall::wall(sf::Vector2f position, sf::Vector2f size, sf::Color color) {
    shape.setPosition(position);
    shape.setSize(size);
    shape.setFillColor(color);
    bounds = shape.getGlobalBounds();
}

wall::wall() : wall(sf::Vector2f(0.0, 0.0), sf::Vector2f(0.0, 0.0), sf::Color::Transparent) {}