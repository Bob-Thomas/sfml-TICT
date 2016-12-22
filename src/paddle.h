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

    int hit_direction(movable_entity &e);

        void move(sf::Vector2f pos);
    sf::FloatRect getBounds() const;

    void update(float delta);

    void input(sf::Event& e){}

    void write(std::ofstream &s) {}

    sf::Vector2f getPosition() const;

    void setPosition(const sf::Vector2f &position);

    const sf::Vector2f &getVelocity() const;

    void setVelocity(const sf::Vector2f &velocity);


};

#endif //SFML_DEMO_PADDLE_H
