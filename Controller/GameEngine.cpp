//
// Created by Yashar Dabiran on 2018-10-29.
//

#include <vector>
#include <iostream>
#include <string>
#include "GameEngine.h"
#include "../View/GameSetupView.h"
#include "../View/GameFinishView.h"
#include "../Model/Map/riskException.h"

void GameEngine::startGame() {
    initGame();
    mainLoop(5);
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
        players.push_back(new Player(i + 1));
}

void GameEngine::mainLoop(int numberOfIterations) {
    while(numberOfIterations > 0 && map->ownerOfAllCountries() == nullptr) {
        for(Player* &player: players) {
            std::cout << "Player " << to_string(player->getId()) << "'s turn." << std::endl;
            player->reinforce();
            player->attack();
            player->fortify();
        }

        numberOfIterations--;
    }

    GameFinishView gameFinishView;
    if (map->ownerOfAllCountries() != nullptr)
        gameFinishView.announceWinner(map->ownerOfAllCountries());
}

void GameEngine::setOwnershipOfCountriesToOnePlayer() {
    for(auto &country: map->getCountries()) {
        country->setOwner(players[0]);
    }
}

void GameEngine::setOwnershipOfCountriesToRandomPlayers() {
    std::vector<country_ptr> countries = map->getCountries();
    for (int i = 0; i < countries.size() - 1; i++)
        countries[i]->setOwner(players[0]);
    countries[countries.size() - 1]->setOwner(players[1]);
}
