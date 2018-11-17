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
   

public:
    ~GameEngine();

    /**
     * Initializes the game: Assignment 2 Part 1
     */
    void initGame();

    /**
     * Call this function if you want to start the game
     */
    void startGame();

    // TODO: For next assignment put it as a private function
    /**
     * It will execute the main loop of the game
     */
    void mainLoop();

    int getNumberOfPlayers();
    int getNumberOfCardsInDeck();
    int getNumberOfCountriesInMap();

    /**
     * TEST ONLY
     * Gives all of the countries to player 1
     */
    void setOwnershipOfCountriesToOnePlayer();

    /**
     * TEST ONLY
     * Gives all the countries to random players
     */
    void setOwnershipOfCountriesToRandomPlayers();

    void startUpPhase();

  

    static vector<Player*> order_play(vector <Player*> array);       // determining the order of play
	static void distributing_countries(vector <country_ptr> array, vector<Player*> ordered_turns); //distibuting the countries to the players
	static void distributing_armies(vector<Player*> ordered_turns); //distributing the armies to the players
	static void placing_armies(vector<Player*> ordered_turns);

    void autoPlaceArmies(std::vector<Player*>);


};


#endif //RISKGAME_GAMEENGINE_H
