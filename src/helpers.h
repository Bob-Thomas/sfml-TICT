//
// Created by endargon on 12/9/16.
//

#ifndef SFML_DEMO_HELPERS_H
#define SFML_DEMO_HELPERS_H

#include <SFML/Window.hpp>

class helpers {
public:
    static sf::Vector2f Vector2f_from_Vector2i(sf::Vector2i rhs) {
        return sf::Vector2f(
                static_cast< float >( rhs.x ),
                static_cast< float >( rhs.y )
        );
    }
};

#endif //SFML_DEMO_HELPERS_H
