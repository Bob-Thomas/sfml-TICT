//
// Created by endargon on 12/9/16.
//

#include "draggable_line.h"

draggable_line::draggable_line(sf::Vector2f start, sf::Color color) : position(start), color(color) {
    shape = sf::RectangleShape(start);
    shape.setFillColor(color);

}

void draggable_line::draw(sf::RenderWindow &w) const {
    w.draw(shape);
}

void draggable_line::move(sf::Vector2f position) {
    this->position = position;
    shape.setPosition(position);
}

sf::FloatRect draggable_line::getBounds() const {
    return shape.getGlobalBounds();
}

sf::Vector2f draggable_line::getPosition() const {
    return shape.getPosition();
}

void draggable_line::write(std::ofstream &s) {
    s << "(" << position.x << "," << position.y << ") ";
    s << "LINE ";
    for (auto c : colors) {
        if (c.color == color) {
            s << c.name << " ";
            break;
        }
    }

}