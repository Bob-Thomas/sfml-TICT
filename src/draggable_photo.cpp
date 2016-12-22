//
// Created by endargon on 12/9/16.
//

#include "draggable_photo.h"

draggable_photo::draggable_photo(std::string src, sf::Vector2f pos, sf::Vector2f scale) : position(pos), src(src) {
    sprite.setPosition(position);
    texture.loadFromFile(src);
    sprite.setTexture(texture, true);
    sprite.setScale(scale);

}

void virtual draggable_photo::draw(sf::RenderWindow &w) const {
    w.draw(sprite);
}

void draggable_photo::write(std::ofstream &s) {
    s << "(" << position.x << "," << position.y << ") ";
    s << "PICTURE ";
    s << src;
}

sf::Vector2f virtual draggable_photo::getPosition() const {
    return sprite.getPosition();
}

void virtual draggable_photo::move(sf::Vector2f position) {
    this->position = position;
    sprite.setPosition(position);
}

sf::FloatRect virtual draggable_photo::getBounds() const {
    return sprite.getGlobalBounds();
}