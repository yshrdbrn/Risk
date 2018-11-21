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
private:
    State state;
//    map_ptr map;
//    std::vector<Player *> players;
//    Deck *deck;

    /**
     * Gives countries to players and distribute armies
     */
    void startUpPhase();

    /**
     * It will execute the main loop of the game
     */
    void mainLoop();

    /**
    * Initializes the game:
    */
    void initGame();

    /**
     * Checks if player has lost
     * @param player the person to check
     * @return if the player does not own any countries (has lost)
     */
    bool playerDoesNotOwnAnyCountries(Player *player);

    // Asks console if the user wants to change strategy
    void askIfWantToChangeStrategy(Player *player);

public:
    /**
     * Call this function if you want to start the game
     */
    void startGame();

    int getNumberOfPlayers();
    int getNumberOfCardsInDeck();
    int getNumberOfCountriesInMap();
};


#endif //RISKGAME_GAMEENGINE_H
