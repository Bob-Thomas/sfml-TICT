//
// Created by endargon on 12/9/16.
//

#include "selectable.h"

void selectable::input(sf::Event &event) {
    switch(event.type) {
        case sf::Event::MouseMoved:
            if(draggin) {
                current_pos = sf::Vector2f(event.mouseMove.x, event.mouseMove.y);
                move(sf::Vector2f(current_pos.x - entered_pos.x, current_pos.y - entered_pos.y));
            }
            break;

        case sf::Event::MouseButtonPressed:
            if(event.mouseButton.button == sf::Mouse::Left && getBounds().contains( sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                draggin = true;
                entered_pos = sf::Vector2f(event.mouseButton.x - getPosition().x, event.mouseButton.y - getPosition().y);
            }
            break;
        case sf::Event::MouseButtonReleased:
            if(event.mouseButton.button == sf::Mouse::Left) {
                entered_pos = {0, 0};
                current_pos = {0 ,0};
                draggin = false;
            }
            break;
    }
}

void selectable::update(float delta) {
    if(draggin) {
    }
}