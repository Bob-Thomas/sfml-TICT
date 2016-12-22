//
// Created by endargon on 12/9/16.
//

#ifndef SFML_DEMO_SELECTABLE_H
#define SFML_DEMO_SELECTABLE_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Window/Event.hpp>
#include "movable_entity.h"

class selectable : public movable_entity {
    protected:
        bool draggin = false;
        sf::Vector2f entered_pos{0, 0};
        sf::Vector2f current_pos{0, 0};
    public:

        void input(sf::Event &event);

        void update(float delta);

};

#endif //SFML_DEMO_SELECTABLE_H
