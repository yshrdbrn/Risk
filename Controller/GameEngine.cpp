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
#include "../View/PhaseObserver.h"
#include "../View/StatisticsObserver.h"

void GameEngine::startGame() {
    initGame();

    startUpPhase();

    mainLoop();
}

int GameEngine::getNumberOfPlayers() {
    return state.getPlayers().size();
}

int GameEngine::getNumberOfCardsInDeck() {
    return state.getDeck()->getTotalCards();
}

int GameEngine::getNumberOfCountriesInMap() {
    return state.getMap()->numberOfCountries();
}

void GameEngine::initGame() {
    // Set the observers
    state.attach(new PhaseObserver(&state));
    state.attach(new StatisticsObserver(&state));

    MapLoader mapLoader;
    GameSetupView gameSetupView;
    std::vector<std::string> mapNames = mapLoader.getListOfAllMapFiles();

    // Check if the chosen map is valid
    while(true) {
        try {
            int mapNumber = gameSetupView.promptUserToChooseMapFile(mapNames);
            state.setMap(mapLoader.createMapWithFileName(mapNames[mapNumber]));
            break;
        } catch (RiskException &e) {
            gameSetupView.showError(e.what());
        }
    }

    // Create the Deck
    state.setDeck(new Deck(state.getMap()->numberOfCountries()));

    int numberOfPlayers = gameSetupView.promptUserToChooseNumberOfPlayers(MIN_PLAYERS, MAX_PLAYERS);

    std::vector<Player *> players;
//    players.push_back(new Player(1, new HumanStrategy()));
    for (int i = 0; i < numberOfPlayers; i++) {
        if (i % 2 == 1)
            players.push_back(new Player(i + 1, new AggressiveComputerStrategy()));
        else
            players.push_back(new Player(i + 1, new BenevolentComputerStrategy()));
    }

    state.setPlayers(players);
}

void GameEngine::startUpPhase() {

    auto temp = startup::order_play(state.getPlayers());

    startup::distributing_countries(state.getMap()->getCountries(), temp);
    startup::distributing_armies(temp);
    startup::placing_armies(temp);
}

void GameEngine::mainLoop() {
    map_ptr map = state.getMap();
    auto players = state.getPlayers();
    state.calculateNewPercentage();

    while(map->ownerOfAllCountries() == nullptr) {
        for(Player* &player: players) {
            if (playerDoesNotOwnAnyCountries(player))
                continue;

            state.setPhaseState("Player " + to_string(player->getId()) + "'s turn.");
//            std::cout << "Player " << to_string(player->getId()) << "'s turn." << std::endl;
//            std::cout << "The countries you own:" << std::endl;
//            auto countries = player->getCountries();
//            for(int i = 0; i < countries.size(); i++)
//                std::cout << countries[i]->getName() << ", armies: " << countries[i]->getNumOfArmies() << std::endl;
            player->reinforce(&state);
            player->attack(&state);
            player->fortify(&state);

//            std::cout << "The countries you own now:" << std::endl;
//            countries = player->getCountries();
//            for(int i = 0; i < countries.size(); i++)
//                std::cout << countries[i]->getName() << ", armies: " << countries[i]->getNumOfArmies() << std::endl;
        }
    }

    GameFinishView gameFinishView;
    if (map->ownerOfAllCountries() != nullptr)
        gameFinishView.announceWinner(map->ownerOfAllCountries());
}

bool GameEngine::playerDoesNotOwnAnyCountries(Player *player) {
    if (player->getCountries().size() == 0)
        return true;
    return false;
}
