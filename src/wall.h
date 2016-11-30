//
// Created by endargon on 11/30/16.
//

#ifndef SFML_DEMO_WALL_H
#define SFML_DEMO_WALL_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class wall {

    sf::RectangleShape shape;
    sf::FloatRect bounds;
    sf::Vector2f position;
    sf::Vector2i size;

public:
    wall();
    wall(sf::Vector2f position, sf::Vector2f size, sf::Color color);

    sf::FloatRect getBounds() {
        return bounds;
    }
    void draw(sf::RenderWindow &w) {
        w.draw(shape);
    }
};
#endif //SFML_DEMO_WALL_H
