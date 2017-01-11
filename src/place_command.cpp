//
// Created by endargon on 1/11/17.
//

#include "place_command.h"

place_command::place_command(game &g, int row, int col) : g(g), row(row), col(col) {
    previous_value = g.get_board()[row][col];
    previous_turn = g.get_turn();
}

void place_command::execute() {
    g.set_turn(previous_turn);
    g.set_board_value(row, col, g.get_turn());
}