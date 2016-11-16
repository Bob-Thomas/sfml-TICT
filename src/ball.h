//
// Created by endargon on 11/16/16.
//

#ifndef SFML_DEMO_BALL_H
#define SFML_DEMO_BALL_H


#include<SFML/Graphics.hpp>

class ball {
private:

    sf::Vector2f position;
    float size;

public:

    ball(sf::Vector2f position, float size = 30.0);

    void draw(sf::RenderWindow &window) const;

    void move(sf::Vector2f delta);

    void jump(sf::Vector2f target);
};

#endif //SFML_DEMO_BALL_H
