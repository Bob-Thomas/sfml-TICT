//
// Created by endargon on 11/16/16.
//

#include "ball.h"

ball::ball(sf::Vector2f position, sf::Vector2f velocity, sf::Color color, float size) :
        position{position},
        velocity(velocity),
        color(color),
        size(size) {
    circle.setFillColor(color);
    circle.setRadius(size);
    circle.setPosition(position);
}

void ball::draw(sf::RenderWindow &window) const {
    window.draw(circle);
}


void ball::bounce(int direction) {
    velocity = sf::Vector2f{direction * velocity.x, -direction * velocity.y};
}

sf::FloatRect ball::getBounds() const {
    return circle.getGlobalBounds();
}

float ball::getSpeed() {
    return speed;
}

void ball::setVelocity(sf::Vector2f velocity) {
    this->velocity = velocity;
}

sf::Vector2f ball::getVelocity() {
    return velocity;
}

void ball::setSpeed(float speed) {
    this->speed = speed;
}

void ball::update(float delta) {
    if (!draggin) {
        move(circle.getPosition() + (delta * velocity));
    }
}
