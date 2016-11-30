//
// Created by endargon on 11/25/16.
//

#ifndef SFML_DEMO_ACTION_H
#define SFML_DEMO_ACTION_H

#include <functional>
#include <SFML/Window.hpp>
#include "wall.h"
#include "storage.h"

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

    action(
            sf::FloatRect rect,
            storage<wall, 4> walls, std::function<void()> work) :
            condition(
                    [rect, walls]() -> bool {
                        for(wall w : walls) {
                            if(rect.intersects(w.getBounds())) {
                                return true;
                            }
                        }
                        return false;
                    }),
            work(work) { }

    void operator()() {
        if (condition()) {
            work();
        }
    }
};

#endif //SFML_DEMO_ACTION_H
