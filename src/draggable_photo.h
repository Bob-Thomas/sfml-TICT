//
// Created by endargon on 12/9/16.
//

#include <SFML/Graphics.hpp>
#include "selectable.h"
#include "colors.h"
#include <fstream>

#ifndef SFML_DEMO_DRAGGABLE_PHOTO_H
#define SFML_DEMO_DRAGGABLE_PHOTO_H

class draggable_photo : public selectable {
        sf::Sprite sprite;
        sf::Texture texture;
        sf::Vector2f position;
        std::string src;
    public:
        draggable_photo(std::string src, sf::Vector2f pos, sf::Vector2f scale);

        virtual void draw(sf::RenderWindow &w) const;

        void write(std::ofstream &s);

        virtual sf::FloatRect getBounds() const;

        virtual sf::Vector2f getPosition() const;

        virtual void move(sf::Vector2f position);


};

#endif //SFML_DEMO_DRAGGABLE_PHOTO_H
