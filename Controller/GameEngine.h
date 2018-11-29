//
// Created by Yashar Dabiran on 2018-10-29.
//

#ifndef RISKGAME_GAMEENGINE_H
#define RISKGAME_GAMEENGINE_H

#include <vector>
#include "../Model/Player/Player.h"
#include "State.h"

const int MIN_PLAYERS = 2;
const int MAX_PLAYERS = 6;

class GameEngine {
protected:
    State state;

    /**
     * Gives countries to players and distribute armies
     */
    void startUpPhase();

    /**
     * It will execute the main loop of the game
     */
    virtual void mainLoop() = 0;

    /**
     * Checks if player has lost
     * @param player the person to check
     * @return if the player does not own any countries (has lost)
     */
    bool playerDoesNotOwnAnyCountries(Player *player);


public:
    /**
     * Call this function if you want to start the game
     */
    virtual void startGame() = 0;

    virtual ~GameEngine() = default;
};


#endif //RISKGAME_GAMEENGINE_H
