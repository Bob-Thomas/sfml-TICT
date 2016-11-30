//
// Created by endargon on 11/16/16.
//

#ifndef SFML_DEMO_BALL_H
#define SFML_DEMO_BALL_H


#include<SFML/Graphics.hpp>
#include <stdlib.h>
#include "math.h"
#include "movable_entity.h"

class ball : public movable_entity {
    private:
        sf::CircleShape circle;
        sf::Vector2f position;
        sf::Vector2f velocity;
        float speed = 2;
        float size;

    public:

        ball(sf::Vector2f position, sf::Vector2f velocity, sf::Color color, float size = 30.0);

        void draw(sf::RenderWindow &window) const;

        void update(float delta);

        void bounce(int direction);

        sf::FloatRect getBounds() const;

        sf::Vector2f getPosition() const{
            return circle.getPosition();
        }

        void setSpeed(float speed);

        float getSpeed();

        void setVelocity(sf::Vector2f velocity);

        sf::Vector2f getVelocity();
};

#endif //SFML_DEMO_BALL_H
