//
// Created by smart on 11/30/2016.
//

#ifndef SFML_DEMO_MOVABLE_ENTITY_H
#define SFML_DEMO_MOVABLE_ENTITY_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "entity.h"

class movable_entity : public entity {
public:
    virtual void move(sf::Vector2f pos) = 0;
};

#endif //SFML_DEMO_MOVABLE_ENTITY_H
