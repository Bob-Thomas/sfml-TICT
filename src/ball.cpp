//
// Created by endargon on 11/16/16.
//

#include "ball.h"

ball::ball(sf::Vector2f position, float size) :
        position{position},
        size{size} { }

void ball::draw(sf::RenderWindow &window) const {
    sf::CircleShape circle;
    circle.setRadius(size);
    circle.setPosition(position);
    window.draw(circle);
}


void ball::move(sf::Vector2f delta) {
    position += delta;
}

void ball::jump(sf::Vector2f target) {
    position = target;
}
