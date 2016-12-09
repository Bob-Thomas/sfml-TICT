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

int paddle::hit_direction(movable_entity &e) {
    float dx = (getBounds().left + getBounds().width / 2) - (e.getBounds().left + e.getBounds().width / 2);
    float dy = (getBounds().top + getBounds().height / 2) - (e.getBounds().top + e.getBounds().height / 2);
    float width = (getBounds().width + e.getBounds().width) / 2;
    float height = (getBounds().height + e.getBounds().height) / 2;
    float crossWidth = width * dy;
    float crossHeight = height * dx;
    //
    if (abs(dx) <= width && abs(dy) <= height) {
        if (crossWidth > crossHeight) {
            return (crossWidth > (-crossHeight)) ? DOWN : LEFT;
        } else {
            return (crossWidth > -(crossHeight)) ? RIGHT : UP;
        }
    }
    return -1;
}