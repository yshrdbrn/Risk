//
// Created by Yashar Dabiran on 2018-10-29.
//

#ifndef RISKGAME_GAMEENGINE_H
#define RISKGAME_GAMEENGINE_H

#include <vector>
#include "../Model/Maploader/mapLoader.h"
#include "../Model/Player/Player.h"
#include "../Model/Cards/Deck.h"

const int MIN_PLAYERS = 2;
const int MAX_PLAYERS = 6;

class GameEngine {
private:
    map_ptr map;
    std::vector<Player *> players;
    Deck *deck;

    /**
     * Initializes the game: Assignment 2 Part 1
     */
    void initGame();

public:
    ~GameEngine();

    /**
     * Call this function if you want to start the game
     */
    void startGame();

    int getNumberOfPlayers();
    int getNumberOfCardsInDeck();
    int getNumberOfCountriesInMap();
};


#endif //RISKGAME_GAMEENGINE_H
