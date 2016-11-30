//
// Created by endargon on 11/16/16.
//

#ifndef SFML_DEMO_BALL_H
#define SFML_DEMO_BALL_H


#include<SFML/Graphics.hpp>
#include <stdlib.h>
#include "math.h"
class ball {
private:
    sf::CircleShape circle;
    sf::FloatRect bounds;
    sf::Vector2f position;
    float speed = 2;
    float velocity;
    float size;

public:

    ball(sf::Vector2f position, float size = 30.0);

    void draw(sf::RenderWindow &window);

    const sf::FloatRect getBounds() {
        return bounds;
    }

    void setSpeed(float speed) {
        this->speed = speed;
    }
    float getSpeed() {
        return speed;
    }

    void setVelocity(float velocity) {
        this->velocity =velocity;
    }

    float getVelocity() {
        return velocity;
    }

    void jump(sf::Vector2f target);
};

#endif //SFML_DEMO_BALL_H
