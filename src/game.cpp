//
// Created by endargon on 1/11/17.
//

#include "game.h"

game::game() { }

void game::run() {
    commands = {};
    board = {{{{0, 0, 0}},{{0, 0, 0}},{{0, 0, 0}}}};
    running = 1;
}

void game::stop() {
    running = 0;
}

void game::print_board() {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if (board[i][j] == 1) {
                std::cout << "X ";
            } else if (board[i][j] == 2) {
                std::cout << "O ";
            } else {
                std::cout << "- ";
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void game::place(command *c) {
    c->execute();
    commands.push_back(c);
}

int game::get_winner(int row, int col) {
    if (
            (board[row][0] == get_turn() && board[row][1] == get_turn() && board[row][2] == get_turn()) ||
            (board[0][col] == get_turn() && board[1][col] == get_turn() && board[2][col] == get_turn()) ||

            ((board[0][0] == get_turn() && board[1][1] == get_turn() && board[2][2] == get_turn())) ||
            (board[0][2] == get_turn() && board[1][1] == get_turn() && board[2][0] == get_turn())) {
        stop();
        return get_turn();
    }
    if(std::count_if(board[0].begin(), board[0].end(), [](int i){return i == 1 || i == 2;}) == 3 &&
       std::count_if(board[1].begin(), board[1].end(), [](int i){return i == 1 || i == 2;}) == 3  &&
       std::count_if(board[2].begin(), board[2].end(), [](int i){return i == 1 || i == 2;}) == 3 ) {
        stop();
        return -666;
    }
    return -1;
}

void game::undo() {
    board = {{{{0, 0, 0}},{{0, 0, 0}},{{0, 0, 0}}}};
    if (commands.size() > 0) {
        commands.pop_back();
        std::for_each(commands.begin(), commands.end(), [](command *c) {
            c->execute();
        });
    }
}

board_type game::get_board() {
    return board;
}

void game::set_board(board_type &b) {
    board = b;
}

void game::set_board_value(int row, int col, int value) {
    if(board[row][col] == 0) {
        board[row][col] = value;
        if (get_winner(row, col) > 0) {
            std::cout << "winner player " << get_turn() << "\n";
        } else if (get_winner(row, col) == -666) {
            std::cout << "IT IS A TIE" << std::endl;
        }
        switch_turn();
    } else {
        std::cout << "Place already in use\n";
    }
}

void game::set_turn(int t) {
    turn = t;
}

void game::switch_turn() {
    if (turn == 1) {
        turn = 2;
    } else {
        turn = 1;
    }
}

int game::get_turn() {
    return turn;
}

bool game::is_running() {
    return running;
}