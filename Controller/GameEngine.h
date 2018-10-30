//
// Created by Yashar Dabiran on 2018-10-29.
//

#ifndef RISKGAME_GAMEENGINE_H
#define RISKGAME_GAMEENGINE_H

#include <vector>
#include "../Model/Maploader/mapLoader.h"
#include "../Model/Player/Player.h"

const int MIN_PLAYERS = 2;
const int MAX_PLAYERS = 6;

class GameEngine {
private:
    map_ptr map;
    std::vector<Player *> players;

public:
    ~GameEngine();

    void startGame();
};


#endif //RISKGAME_GAMEENGINE_H
