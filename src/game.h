//
// Created by endargon on 1/11/17.
//

#ifndef SFML_DEMO_GAME_H
#define SFML_DEMO_GAME_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include "command.h"

typedef std::array<std::array<int, 3>, 3> board_type;

class game {
    std::vector<command *> commands;
    board_type board{{{{0, 0, 0}}, {{0, 0, 0}}, {{0, 0, 0}}}};
    int turn = 1;
    bool running;
public:
    game();;

    void run();

    void stop();

    void print_board();

    void place(command *c);

    int get_winner(int row, int col);

    void undo();

    board_type get_board();

    void set_board(board_type &b);

    void set_board_value(int row, int col, int value);

    void set_turn(int t);

    void switch_turn();

    int get_turn();

    bool is_running();
};

#endif //SFML_DEMO_GAME_H
