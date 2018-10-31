//
// Created by Yashar Dabiran on 2018-10-30.
//

#include <iostream>
#include <vector>
#include <string>
#include "../Model/Maploader/mapLoader.h"
#include "GameEngine.h"

int main() {
    GameEngine gameEngine;
    gameEngine.startGame();

    // Check Number of Players and Cards and Countries
    std::cout << "Number of players: " << gameEngine.getNumberOfPlayers() << std::endl;
    std::cout << "Number of cards: " << gameEngine.getNumberOfCardsInDeck() << std::endl;
    std::cout << "Number of countries: " << gameEngine.getNumberOfCountriesInMap() << std::endl;

    if (gameEngine.getNumberOfCardsInDeck() == gameEngine.getNumberOfCountriesInMap())
        std::cout << "Number of countries and cards are the same!" << std::endl;
    else
        std::cout << "Number of countries and cards are NOT the same!" << std::endl;
    return 0;
}