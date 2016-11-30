//
// Created by endargon on 11/30/16.
//

#ifndef SFML_DEMO_WALL_H
#define SFML_DEMO_WALL_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "entity.h"

class wall : public entity {

        sf::RectangleShape shape;
        sf::Vector2f position;
        sf::Vector2i size;

    public:
        wall();

        wall(sf::Vector2f position, sf::Vector2f size, sf::Color color);

        void draw(sf::RenderWindow &w) const;

        sf::FloatRect getBounds() const;

        sf::Vector2f getPosition() const{
            return shape.getPosition();
        }

};

#endif //SFML_DEMO_WALL_H
