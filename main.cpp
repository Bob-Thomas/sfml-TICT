#include<SFML/Graphics.hpp>
#include"src/ball.h"
#include "src/action.h"
#include "src/paddle.h"

sf::Vector2f Vector2f_from_Vector2i(sf::Vector2i vector2);

int main() {

    sf::RenderWindow window{sf::VideoMode{640, 480}, "Game"};
    ball my_ball{sf::Vector2f{30, 30.0}, sf::Vector2f(400, 100), sf::Color::Blue};
    paddle my_paddle{sf::Vector2f{320.0, 240.0}, sf::Vector2f(0, 0), sf::Color::Yellow};
    wall walls[4];

    walls[0] = {sf::Vector2f(0.0, 0.0), sf::Vector2f(window.getSize().x, 20), sf::Color::Red}; //top
    walls[1] = {sf::Vector2f(window.getSize().x - 20, 0.0), sf::Vector2f(20.0, window.getSize().y),
                sf::Color::Red}; // right
    walls[2] = {sf::Vector2f(0.0, window.getSize().y - 20), sf::Vector2f(window.getSize().x, 20.0),
                sf::Color::Red}; //bottom
    walls[3] = {sf::Vector2f(0.0, 0.0), sf::Vector2f(20.0, window.getSize().y), sf::Color::Red}; //left

    action actions[] = {
            action([&] { my_paddle.setVelocity({0,0});}),
            action(sf::Keyboard::Left,
                   [&] { my_paddle.setVelocity(sf::Vector2f(-300, 0.0)); }),
            action(sf::Keyboard::Right,
                   [&] { my_paddle.setVelocity(sf::Vector2f(300, 0.0)); }),
            action(sf::Keyboard::Up, [&] { my_paddle.setVelocity(sf::Vector2f(0.0, -300)); }),
            action(sf::Keyboard::Down,
                   [&] { my_paddle.setVelocity(sf::Vector2f(0.0, 300)); }),

            action([&]() -> bool{ return my_paddle.hit_direction(my_ball) == UP;}, [&] { my_ball.bounce(1);}),
            action([&]() -> bool{ return my_paddle.hit_direction(my_ball) == RIGHT;}, [&] { my_ball.bounce(-1);}),
            action([&]() -> bool{ return my_paddle.hit_direction(my_ball) == DOWN;}, [&] { my_ball.bounce(1);}),
            action([&]() -> bool{ return my_paddle.hit_direction(my_ball) == LEFT;}, [&] { my_ball.bounce(-1);}),

            action(my_ball, walls[0], [&] { my_ball.bounce(1); }),
            action(my_ball, walls[1], [&] { my_ball.bounce(-1); }),
            action(my_ball, walls[2], [&] { my_ball.bounce(1); }),
            action(my_ball, walls[3], [&] { my_ball.bounce(-1); })
    };

    sf::Clock clock;
    sf::Time elapsed = clock.restart();

    //60 FPS master race
    const sf::Time update_ms = sf::seconds(1.f / 60.f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        elapsed += clock.restart();
        while (elapsed >= update_ms) {
            float delta = update_ms.asSeconds();
            for (auto &action : actions) {
                action();
            }
            my_ball.update(delta);
            my_paddle.update(delta);
            elapsed -= update_ms;
        }
        window.clear();
        for (wall &w : walls) {
            w.draw(window);
        }
        my_ball.draw(window);
        my_paddle.draw(window);
        window.display();
    }

    return EXIT_SUCCESS;
}

sf::Vector2f Vector2f_from_Vector2i(sf::Vector2i rhs) {
    return sf::Vector2f(
            static_cast< float >( rhs.x ),
            static_cast< float >( rhs.y )
    );
}