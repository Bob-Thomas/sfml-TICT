//
// Created by smart on 11/30/2016.
//

#include "paddle.h"

paddle::paddle(const sf::Vector2f &position, const sf::Vector2f &velocity, sf::Color color) : position(position), velocity(velocity) {
    shape.setFillColor(color);
    shape.setPosition(position);
    shape.setSize({200, 200});
}

void paddle::draw(sf::RenderWindow &w) const {
    w.draw(shape);
}

sf::FloatRect paddle::getBounds() const {
    return shape.getGlobalBounds();
}

void paddle::update(float delta) {
    shape.setPosition(shape.getPosition() + (delta * velocity));
}

sf::Vector2f paddle::getPosition() const {
    return shape.getPosition();
}

void paddle::setPosition(const sf::Vector2f &position) {
    paddle::position = position;
}

const sf::Vector2f &paddle::getVelocity() const {
    return velocity;
}

void paddle::setVelocity(const sf::Vector2f &velocity) {
    paddle::velocity = velocity;
}