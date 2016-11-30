#include<SFML/Graphics.hpp>
#include"src/ball.h"
#include "src/action.h"
#include "src/wall.h"
#include "src/storage.h"

sf::Vector2f Vector2f_from_Vector2i(sf::Vector2i vector2);

int main() {

    sf::RenderWindow window{sf::VideoMode{640, 480}, "Game"};
    ball my_ball{sf::Vector2f{320.0, 240.0}};
    storage<wall, 4> walls;
    walls.add({sf::Vector2f(0.0, 0.0), sf::Vector2f(20.0, window.getSize().y), sf::Color::Red});
    walls.add({sf::Vector2f(0.0, window.getSize().y-20), sf::Vector2f(window.getSize().x, 20.0), sf::Color::Red});
    walls.add({sf::Vector2f(0.0, 0.0), sf::Vector2f(window.getSize().x, 20), sf::Color::Red});
    walls.add({sf::Vector2f(window.getSize().x-20, 0.0), sf::Vector2f(20.0, window.getSize().y), sf::Color::Red});
    action actions[] = {
            action(my_ball.getBounds(), walls, [my_ball, walls] { my_ball.jump(sf::Vector2i(0,0)); })
    };
    while (window.isOpen()) {
        for (auto &action : actions) {
            action();
        }
        window.clear();
        for(wall &w : walls) {
            w.draw(window);
        }
        my_ball.draw(window);
        window.display();

        sf::sleep(sf::milliseconds(20));
    }

    return 0;
}

sf::Vector2f Vector2f_from_Vector2i(sf::Vector2i rhs) {
    return sf::Vector2f(
            static_cast< float >( rhs.x ),
            static_cast< float >( rhs.y )
    );
}