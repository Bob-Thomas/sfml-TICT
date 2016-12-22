//
// Created by endargon on 12/9/16.
//

#ifndef SFML_DEMO_DRAGGABLE_LINE_H
#define SFML_DEMO_DRAGGABLE_LINE_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "selectable.h"
#include "colors.h"
#include <fstream>

struct colors;

class draggable_line : public selectable {
        sf::RectangleShape shape;
        sf::Vector2f position;
        sf::Color color;
    public:
        draggable_line(sf::Vector2f start, sf::Color color);

        void draw(sf::RenderWindow &w) const;;


        void move(sf::Vector2f position);

        sf::FloatRect getBounds() const;;

        sf::Vector2f getPosition() const;

        void write(std::ofstream &s);

};

#endif //SFML_DEMO_DRAGGABLE_LINE_H
