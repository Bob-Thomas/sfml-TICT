//
// Created by endargon on 1/11/17.
//

#ifndef SFML_DEMO_PLACE_COMMAND_H
#define SFML_DEMO_PLACE_COMMAND_H

#include "command.h"
#include "game.h"

class place_command : public command {
    private:
        int previous_value;
        int previous_turn;
        int row, col;
        game &g;
    public:
        place_command(game &g, int row, int col);;
        void execute();
};

#endif //SFML_DEMO_PLACE_COMMAND_H
