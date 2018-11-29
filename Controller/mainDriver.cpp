//
// Created by Yashar Dabiran on 2018-10-31.
//
#include <iostream>
#include <vector>
#include <string>
#include "../Model/Maploader/mapLoader.h"
#include "GameEngine.h"
#include "SinglePlayerGameEngine.h"

int main() {
    GameEngine *gameEngine = new SinglePlayerGameEngine();

    gameEngine->startGame();

    delete gameEngine;
}
