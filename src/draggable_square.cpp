//
// Created by endargon on 12/9/16.
//

#include "draggable_square.h"

draggable_square::draggable_square(sf::Vector2f position, sf::Vector2f size, sf::Color color)
        : position(position), color(color) {
    shape.setPosition(position);
    shape.setSize(size);
    shape.setFillColor(color);
}

void draggable_square::write(std::ofstream &s) {
    s << "(";
    s << position.x;
    s << ",";
    s << position.y;
    s << ") ";
    s << "RECTANGLE ";
    for (auto c : colors) {
        if (c.color == color) {
            s << c.name << " ";
            break;
        }
    }
    s << "(" << shape.getSize().x << "," << shape.getSize().y << ") ";

}

void draggable_square::move(sf::Vector2f position) {
    this->position = position;
    shape.setPosition(position);
}

sf::FloatRect draggable_square::getBounds() const {
    return shape.getGlobalBounds();
}

sf::Vector2f draggable_square::getPosition() const {
    return shape.getPosition();
}