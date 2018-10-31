//
// Created by Yashar Dabiran on 2018-10-29.
//

#include <vector>
#include "GameEngine.h"
#include "../View/GameSetupView.h"
#include "../Model/Map/riskException.h"

void GameEngine::startGame() {
    initGame();
}

GameEngine::~GameEngine() {
    for (auto &player : players)
        delete player;
}

int GameEngine::getNumberOfPlayers() {
    return players.size();
}

int GameEngine::getNumberOfCardsInDeck() {
    return deck->getTotalCards();
}

int GameEngine::getNumberOfCountriesInMap() {
    return map->numberOfCountries();
}

void GameEngine::initGame() {
    MapLoader mapLoader;
    GameSetupView gameSetupView;
    std::vector<std::string> mapNames = mapLoader.getListOfAllMapFiles();

    // Check if the chosen map is valid
    while(true) {
        try {
            int mapNumber = gameSetupView.promptUserToChooseMapFile(mapNames);
            map = mapLoader.createMapWithFileName(mapNames[mapNumber]);
            break;
        } catch (RiskException &e) {
            gameSetupView.showError(e.what());
        }
    }

    // Create the Deck
    deck = new Deck(map->numberOfCountries());

    int numberOfPlayers = gameSetupView.promptUserToChooseNumberOfPlayers(MIN_PLAYERS, MAX_PLAYERS);

    for (int i = 0; i < numberOfPlayers; i++)
        players.push_back(new Player());
}
