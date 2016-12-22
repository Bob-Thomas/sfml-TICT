//
// Created by endargon on 11/16/16.
//

#include "ball.h"

ball::ball(sf::Vector2f position, sf::Vector2f velocity, sf::Color color, int radius) :
        position{position},
        velocity(velocity),
        color(color),
        radius(radius) {
    circle.setFillColor(color);
    circle.setRadius(radius);
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

sf::Vector2f ball::getPosition() const {
    return circle.getPosition();
}

void ball::write(std::ofstream &s) {
    s << "(" << position.x << "," << position.y << ") ";
    s << "CIRCLE ";
    for(auto c : colors) {
        if(c.color == color) {
            s << c.name << " ";
            break;
        }
    }
    s << radius;

}