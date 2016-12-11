//
// Created by endargon on 12/9/16.
//

#ifndef SFML_DEMO_OBJECT_LOADER_H
#define SFML_DEMO_OBJECT_LOADER_H

#include <fstream>
#include <iostream>
#include <regex>
#include <stdlib.h>
#include "entity.h"


class object_loader {
    std::string file_name;
    std::ifstream input;
    std::ifstream output;
    std::vector<entity *> entities = std::vector<entity *>();

public:
    object_loader(std::string file_name) : file_name(file_name) { }

    std::vector<entity *> get_loaded_entities() {
        input.open(file_name);
        while (!input.eof()) {
            std::string line;
            getline(input, line);
            sf::Vector2f pos = read_pos(line);
            break;
        }

        return entities;
    }

    sf::Vector2f read_pos(std::string s_pos) {
        std::cout << s_pos;
        if (s_pos[0] != '(' && s_pos[s_pos.length() - 1] != ')') {
            std::cout << "error\n";
        }
        float x = 0, y = 0;
        bool beep = false;
        std::string s = "0";
        for (int i = 1; i < s_pos.length() - 1; i++) {
            char c = s_pos[i];
            if (isdigit(c)) {
                s += c;
                if (!beep) {
                    x = std::stoi(s);
                } else {
                    y = std::stoi(s);
                }
            }
            if (c == ',') {
                beep = true;
                s = "0";
            }

        }
        return sf::Vector2f(x, y);
    }


    void save_entities(std::vector<entity *> entities) {
        this->entities = entities;
    }
};

#endif //SFML_DEMO_OBJECT_LOADER_H
