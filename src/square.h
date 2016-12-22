//
// Created by endargon on 11/30/16.
//

#ifndef SFML_DEMO_WALL_H
#define SFML_DEMO_WALL_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "entity.h"

class square : public entity {
protected:
    sf::RectangleShape shape;
    sf::Vector2f position;
    sf::Vector2i size;

public:
    square();

    square(sf::Vector2f position, sf::Vector2f size, sf::Color color);

    void draw(sf::RenderWindow &w) const;

    void update(float delta) { }

    void input(sf::Event &e) { }

    void write(std::ofstream &s) {

    }

    sf::FloatRect getBounds() const;

    sf::Vector2f getPosition() const {
        return shape.getPosition();
    }

};

#endif //SFML_DEMO_WALL_H
