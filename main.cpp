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
};


class game {
        std::vector<command *> commands;
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
            commands.push_back(c);
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
            if(std::count_if(board[0].begin(), board[0].end(), [](int i){return i == 1 || i == 2;}) == 3 &&
                    std::count_if(board[1].begin(), board[1].end(), [](int i){return i == 1 || i == 2;}) == 3  &&
                    std::count_if(board[2].begin(), board[2].end(), [](int i){return i == 1 || i == 2;}) == 3 ) {
                stop();
                return -666;
            }
            return -1;
        }


        void undo() {
            board = {{0, 0, 0},
                     {0, 0, 0},
                     {0, 0, 0}};
            if (commands.size() > 0) {
                commands.pop_back();
                std::for_each(commands.begin(), commands.end(), [](command *c) {
                    c->execute();
                });
            }
        }

        board_type get_board() {
            return board;
        }

        void set_board(board_type &b) {
            board = b;
        }

        void set_board_value(int row, int col, int value) {
            assert(board[row][col] == 0);
            board[row][col] = value;
            if (get_winner(row, col) > 0) {
                std::cout << "winner player " << get_turn() << "\n";
            } else if(get_winner(row, col) == -666) {
                std::cout << "IT IS A TIE" << std::endl;
            }
            switch_turn();
        }

        void set_turn(int t) {
            turn = t;
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


class place_command : public command {
        int previous_value;
        int previous_turn;
        int row, col;
        game &g;
    public:
        place_command(game &g, int row, int col) : g(g), row(row), col(col) {
            previous_value = g.get_board()[row][col];
            previous_turn = g.get_turn();
        };

        virtual void execute() {
            g.set_turn(previous_turn);
            g.set_board_value(row, col, g.get_turn());
        }
};

#define GRAPHICAL 1

int main() {
    game g;

    g.run();
    if (GRAPHICAL == 0) {
        std::string decision;
        g.print_board();
        std::cout << "Do a move by typing the position like (0,1) \n type undo to undo your turn0";
        while (g.is_running()) {
            std::cout << "it's player " << g.get_turn() << " his turn\n";
            std::cin >> decision;
            if (decision == "undo") {
                g.undo();
            } else {
                g.place(new place_command(g, decision[0] - 48, decision[1] - 48));
            }
            g.print_board();
        }
    } else {
        auto const grid_size = 100;
        sf::Texture X, O, BG;
        if (!X.loadFromFile("assets/x.png") || !O.loadFromFile("assets/o.png") ||
            !BG.loadFromFile("assets/bg.jpg")) { return -1; }
        sf::Sprite bg_sprite;
        bg_sprite.setTexture(BG);
        sf::RenderWindow window{sf::VideoMode{grid_size * 3, grid_size * 3}, "Game"};
        while (window.isOpen()) {
            sf::Event e;
            while (window.pollEvent(e)) {
                if ((e.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    || e.type == sf::Event::Closed
                        ) {
                    window.close();
                } else if (e.type == sf::Event::MouseButtonPressed && g.is_running()) {
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                    g.place(new place_command(g, mousePosition.x / grid_size, mousePosition.y / grid_size));
                } else if (e.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                    g.undo();
                } else if (e.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
                    g.run();
                }

            }
            window.clear();
            window.draw(bg_sprite);
            for (int i = 0; i < g.get_board().size(); i++) {
                for (int j = 0; j < g.get_board().size(); j++) {
                    sf::Sprite sprite;
                    if (g.get_board()[i][j] == 1) {
                        sprite.setTexture(X);
                    } else if (g.get_board()[i][j] == 2) {
                        sprite.setTexture(O);
                    }
                    sprite.setPosition(i * grid_size, j * grid_size);
                    window.draw(sprite);
                }
            }
            window.display();
        }
    }


    return EXIT_SUCCESS;
}