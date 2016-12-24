#include <stack>
#include <iostream>
#include <vector>
#include <assert.h>
#include <SFML/Graphics.hpp>

/**
 Schrijf een Tic-Tac-Toe (3-op-een-rij) spelletje.
 Maak hiertoe een object voor het spel en een object voor een zet (command pattern).
 Sla het verloop van het spel op in een STL container.
 Implementeer een ‘undo’ feature door het her-afspelen van de gedane zetten behalve de laatste.
 Biedt, met zo min mogelijk code duplicatie, zowel een grafische (SFML) interface als een tekst-only interface.
 */

typedef std::vector<std::vector<int>> board_type;

class command {
    public:
        virtual void execute() = 0;

        virtual void undo() = 0;
};


class game {
        std::stack<command *> commands;
        board_type board{{0, 0, 0},
                         {0, 0, 0},
                         {0, 0, 0}};
        int turn = 1;
        bool running;
    public:
        game() { };

        void run() {
            board = {{0, 0, 0},
                     {0, 0, 0},
                     {0, 0, 0}};
            running = 1;
        }

        void stop() {
            running = 0;
        }

        void print_board() {
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

        void place(command *c) {
            c->execute();
            commands.push(c);
        }

        int get_winner(int row, int col) {
            if (
                    (board[row][0] == get_turn() && board[row][1] == get_turn() && board[row][2] == get_turn()) ||
                    (board[0][col] == get_turn() && board[1][col] == get_turn() && board[2][col] == get_turn()) ||

                    ((board[0][0] == get_turn() && board[1][1] == get_turn() && board[2][2] == get_turn())) ||
                    (board[0][2] == get_turn() && board[1][1] == get_turn() && board[2][0] == get_turn())) {
                stop();
                return get_turn();
            }
            return -1;
        }


        void undo() {
            if (commands.size() > 0) {
                command *c = commands.top();
                c->undo();
                commands.pop();
            }
        }

        board_type get_board() {
            return board;
        }

        void set_board(board_type &b) {
            board = b;
        }

        void set_board_value(int row, int col, int value) {
            assert(board[row][col] != value);
            board[row][col] = value;
            if (get_winner(row, col) > 0) {
                std::cout << "winner player " << get_turn() << "\n";
            }
        }

        void switch_turn() {
            if (turn == 1) {
                turn = 2;
            } else {
                turn = 1;
            }
        }

        int get_turn() {
            return turn;
        }

        bool is_running() {
            return running;
        }
};


class test_command : public command {
        int previous_value;
        int previous_turn;
        int row, col;
        game &g;
    public:
        test_command(game &g, int row, int col) : g(g), row(row), col(col) {
            previous_value = g.get_board()[row][col];
            previous_turn = g.get_turn();
        };

        virtual void execute() {
            g.set_board_value(row, col, g.get_turn());
            g.switch_turn();
            g.print_board();
        }

        virtual void undo() {
            g.set_board_value(row, col, previous_value);
            g.switch_turn();
            g.print_board();
        }
};

#define GRAPHICAL 1

int main() {
    game g;


    std::string decision;
    g.run();
    if (GRAPHICAL == 0) {
        g.print_board();
        std::cout << "Do a move by typing the position like (0,1) \n type undo to undo your turn0";
        while (g.is_running()) {
            std::cout << "it's player " << g.get_turn() << " his turn\n";
            std::cin >> decision;
            if (decision == "undo") {
                g.undo();
            } else {
                g.place(new test_command(g, decision[0] - 48, decision[1] - 48));
            }
        }
    } else {
        sf::RenderWindow window{sf::VideoMode{640, 480}, "Game"};
        sf::vector<
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            window.clear();
            window.display();
        }
    }


    return EXIT_SUCCESS;
}