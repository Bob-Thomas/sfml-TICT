//
// Created by endargon on 11/16/16.
//

#ifndef SFML_DEMO_BALL_H
#define SFML_DEMO_BALL_H


#include<SFML/Graphics.hpp>
#include <stdlib.h>
#include "math.h"
#include "movable_entity.h"
#include "selectable.h"
#include "helpers.h"
#include "colors.h"
#include <fstream>

class ball : public selectable {
    private:
        sf::CircleShape circle;
        sf::Vector2f position;
        sf::Vector2f velocity;
        sf::Color color;
        float speed = 2;
        int radius;

    public:


        ball(sf::Vector2f position, sf::Vector2f velocity, sf::Color color, int radius = 30);

        void draw(sf::RenderWindow &window) const;

        void bounce(int direction);

        sf::FloatRect getBounds() const;

        sf::Vector2f getPosition() const;

        void update(float delta);

        void setSpeed(float speed);

        float getSpeed();

        void setVelocity(sf::Vector2f velocity);

        void move(sf::Vector2f position) {
            this->position = position;
            circle.setPosition(position);
        }

        sf::Vector2f getVelocity();

        void write(std::ofstream &s);
};

#endif //SFML_DEMO_BALL_H
