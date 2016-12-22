//
// Created by endargon on 12/20/16.
//

#ifndef SFML_DEMO_COLORS_H
#define SFML_DEMO_COLORS_H

#include <SFML/Graphics/Color.hpp>

const struct {
    const char *name;
    sf::Color color;
} colors[]{
        {"yellow", sf::Color::Yellow},
        {"red",    sf::Color::Red},
        {"blue",   sf::Color::Blue},
};
#endif //SFML_DEMO_COLORS_H
