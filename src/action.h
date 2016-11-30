//
// Created by endargon on 11/25/16.
//

#ifndef SFML_DEMO_ACTION_H
#define SFML_DEMO_ACTION_H

#include <functional>
#include <SFML/Window.hpp>
#include <iostream>
#include "wall.h"
#include "storage.h"
#include "paddle.h"

class action {
    private:
        std::function<bool()> condition;
        std::function<void()> work;

    public:
        action(
                sf::Keyboard::Key key,
                std::function<void()> work
        ) :
                condition(
                        [key]() -> bool { return sf::Keyboard::isKeyPressed(key); }
                ),
                work(work) { };

        action(
                sf::Mouse::Button button,
                std::function<void()> work
        ) :
                condition(
                        [button]() -> bool { return sf::Mouse::isButtonPressed(button); }),
                work(work) { }

        action(ball &b, wall &w, std::function<void()> work)
                : condition([&w, &b]() -> bool {
            return b.getBounds().intersects(w.getBounds());
        }),
                  work(work) { }

        action(std::function<bool()> test, std::function<void()> work) :
            condition([test]() -> bool {
                return test();
            }), work(work){}

        action(std::function<void()> work)
                : condition([]() -> bool { return true; }), work(work) { }

        void operator()() {
            if (condition()) {
                work();
            }
        }
};

#endif //SFML_DEMO_ACTION_H
