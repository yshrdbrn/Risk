//
// Created by Yashar Dabiran on 2018-10-31.
//
#include <iostream>
#include <vector>
#include <string>
#include "../Model/Maploader/mapLoader.h"
#include "GameEngine.h"
#include "SinglePlayerGameEngine.h"
#include "TournamentGameEngine.h"
#include "../View/GameSetupView.h"

int main() {

    GameSetupView gameSetupView;
    if(gameSetupView.chooseGameType() == "tournament"){
        GameEngine *gameEngine = new TournamentGameEngine();
        gameEngine->startGame();
        delete gameEngine;
    }
    else {
        GameEngine *gameEngine = new SinglePlayerGameEngine();
        gameEngine->startGame();
        delete gameEngine;
    }
}
