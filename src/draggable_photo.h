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
    draggable_photo(std::string src, sf::Vector2f pos, sf::Vector2f scale) : position(pos), src(src) {
        sprite.setPosition(position);
        texture.loadFromFile(src);
        sprite.setTexture(texture, true);
        sprite.setScale(scale);

    }
    virtual void draw(sf::RenderWindow &w) const {
        w.draw(sprite);
    }

    void write(std::ofstream &s) {
        s << "(" << position.x << "," << position.y << ") ";
        s << "PICTURE ";
        s << src;
    }

    virtual sf::FloatRect getBounds() const {
        return sprite.getGlobalBounds();
    }

    virtual sf::Vector2f getPosition() const {
        return sprite.getPosition();
    }

    virtual void move(sf::Vector2f position) {
        this->position = position;
        sprite.setPosition(position);
    }


};
#endif //SFML_DEMO_DRAGGABLE_PHOTO_H
