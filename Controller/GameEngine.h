//
// Created by Yashar Dabiran on 2018-10-29.
//

#ifndef RISKGAME_GAMEENGINE_H
#define RISKGAME_GAMEENGINE_H

#include <vector>
#include "../Model/Maploader/mapLoader.h"

class GameEngine {
private:
    map_ptr map;

public:
    void startGame();
};


#endif //RISKGAME_GAMEENGINE_H
