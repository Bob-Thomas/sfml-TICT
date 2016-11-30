//
// Created by smart on 11/30/2016.
//

#ifndef SFML_DEMO_PADDLE_H
#define SFML_DEMO_PADDLE_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>
#include <math.h>
#include "movable_entity.h"

class paddle : public movable_entity {
    private:

        sf::RectangleShape shape;
        sf::Vector2f position;
        sf::Vector2f velocity;

    public:
        paddle(const sf::Vector2f &position, const sf::Vector2f &velocity, sf::Color color);

        void draw(sf::RenderWindow &w) const;

        //http://stackoverflow.com/a/29861691/3094496 - Detect which side of a rectangle is colliding with another rectangle
        int hit_direction(movable_entity &e) {
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


        sf::FloatRect getBounds() const;

        void update(float delta);

        sf::Vector2f getPosition() const;

        void setPosition(const sf::Vector2f &position);

        const sf::Vector2f &getVelocity() const;

        void setVelocity(const sf::Vector2f &velocity);


};

#endif //SFML_DEMO_PADDLE_H
