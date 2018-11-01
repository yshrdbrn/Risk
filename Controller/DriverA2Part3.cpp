//
// Created by Yashar Dabiran on 2018-10-31.
//
#include <iostream>
#include <vector>
#include <string>
#include "../Model/Maploader/mapLoader.h"
#include "GameEngine.h"

int main() {
    GameEngine gameEngine;
    gameEngine.initGame();

    // Each player will get their turn:
    gameEngine.setOwnershipOfCountriesToRandomPlayers();
    gameEngine.mainLoop(1);

    // Game ends if a player owns all countries
    std::cout << "\nGiving all the countries to player 1..." << std::endl;
    gameEngine.setOwnershipOfCountriesToOnePlayer();
    gameEngine.mainLoop(1);
}
