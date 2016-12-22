//
// Created by smart on 11/30/2016.
//

#ifndef SFML_DEMO_ENTITY_H
#define SFML_DEMO_ENTITY_H

#include <SFML/Graphics/RenderWindow.hpp>

enum direction {
    UP, DOWN, LEFT, RIGHT
};

class entity {
public:
    virtual void draw(sf::RenderWindow &w) const = 0;

    virtual sf::FloatRect getBounds() const = 0;

    virtual sf::Vector2f getPosition() const = 0;

    virtual void update(float delta) = 0;

    virtual void input(sf::Event &event) = 0;

    virtual void write(std::ofstream &s) = 0;


};

#endif //SFML_DEMO_ENTITY_H
