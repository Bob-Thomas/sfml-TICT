#include<SFML/Graphics.hpp>
#include"src/ball.h"

sf::Vector2f Vector2f_from_Vector2i(sf::Vector2i vector2);

int main() {

    sf::RenderWindow window{sf::VideoMode{640, 480}, "SFML window"};
    ball my_ball{sf::Vector2f{320.0, 240.0}};



    while (window.isOpen()) {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            my_ball.move(sf::Vector2f{-1, 0});
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            my_ball.move(sf::Vector2f{+1, 0});
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            my_ball.move(sf::Vector2f{0, -1});
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            my_ball.move(sf::Vector2f{0, +1});
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            my_ball.jump(Vector2f_from_Vector2i(sf::Mouse::getPosition(window)));
        }

        window.clear();
        my_ball.draw(window);
        window.display();

        sf::sleep(sf::milliseconds(20));
    }

    return 0;
}

sf::Vector2f Vector2f_from_Vector2i( sf::Vector2i rhs ){
    return sf::Vector2f(
            static_cast< float >( rhs.x ),
            static_cast< float >( rhs.y )
    );
}