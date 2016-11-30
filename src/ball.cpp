//
// Created by endargon on 11/16/16.
//

#include "ball.h"

ball::ball(sf::Vector2f position, float size) :
        position{position},
        size{size} {
    circle.setRadius(size);
    circle.setPosition(position);
    bounds = circle.getGlobalBounds();
}

void ball::draw(sf::RenderWindow &window) {
    sf::Vector2f new_pos(circle.getPosition().x + speed, circle.getPosition().y);
    circle.setPosition(new_pos);
    window.draw(circle);
}

void ball::jump(sf::Vector2f target) {
    position = target;
}
