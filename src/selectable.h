//
// Created by endargon on 12/9/16.
//

#ifndef SFML_DEMO_SELECTABLE_H
#define SFML_DEMO_SELECTABLE_H

#include <SFML/Graphics/Drawable.hpp>
#include "movable_entity.h"

class selectable : public movable_entity {
protected:
    bool selected = false;
    sf::Vector2f entered_pos{0, 0};
public:
    void select(sf::Vector2f mouse_pos) {
        if (this->getBounds().contains(mouse_pos)) {
            if (entered_pos != sf::Vector2f{0, 0}) {
                entered_pos = mouse_pos;
            }
            selected = true;
        }
    }

    void drag(sf::Vector2f mouse_pos) {
        this->move(sf::Vector2f(mouse_pos.x - entered_pos.x, mouse_pos.y - entered_pos.y));
    }

    void deselect() {
        selected = false;
        entered_pos = {0, 0};
    }

    bool is_selected() {
        return selected;
    }


};

#endif //SFML_DEMO_SELECTABLE_H
