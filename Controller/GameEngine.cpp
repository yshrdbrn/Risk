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
#include "./start_up_phase/startup.h"
#include "../Model/Player/HumanStrategy.h"
#include "../Model/Player/AggressiveComputerStrategy.h"
#include "../Model/Player/BenevolentComputerStrategy.h"

void GameEngine::startGame() {
    initGame();

    startUpPhase();

    mainLoop();
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

//    players.push_back(new Player(1, new HumanStrategy()));
    for (int i = 0; i < numberOfPlayers; i++) {
        if (i % 2 == 1)
            players.push_back(new Player(i + 1, new AggressiveComputerStrategy()));
        else
            players.push_back(new Player(i + 1, new BenevolentComputerStrategy()));
    }
}

void GameEngine::startUpPhase() {

    auto temp = startup::order_play(players);

    startup::distributing_countries(map->getCountries(), temp);
    startup::distributing_armies(temp);
    startup::placing_armies(temp);
}

void GameEngine::mainLoop() {
    while(map->ownerOfAllCountries() == nullptr) {
        for(Player* &player: players) {
            std::cout << "Player " << to_string(player->getId()) << "'s turn." << std::endl;
            std::cout << "The countries you own:" << std::endl;
            auto countries = player->getCountries();
            for(int i = 0; i < countries.size(); i++)
                std::cout << countries[i]->getName() << ", armies: " << countries[i]->getNumOfArmies() << std::endl;
            player->reinforce();
            player->attack();
            player->fortify();

            std::cout << "The countries you own now:" << std::endl;
            countries = player->getCountries();
            for(int i = 0; i < countries.size(); i++)
                std::cout << countries[i]->getName() << ", armies: " << countries[i]->getNumOfArmies() << std::endl;
        }
    }

    GameFinishView gameFinishView;
    if (map->ownerOfAllCountries() != nullptr)
        gameFinishView.announceWinner(map->ownerOfAllCountries());
}