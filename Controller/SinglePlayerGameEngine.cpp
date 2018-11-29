//
// Created by Yashar Dabiran on 2018-11-29.
//

#include <vector>
#include <iostream>
#include <string>
#include "SinglePlayerGameEngine.h"
#include "../View/GameSetupView.h"
#include "../View/GameFinishView.h"
#include "../Model/Map/riskException.h"
#include "./start_up_phase/startup.h"
#include "../Model/Player/HumanStrategy.h"
#include "../Model/Player/AggressiveComputerStrategy.h"
#include "../Model/Player/BenevolentComputerStrategy.h"
#include "../Model/Player/RandomComputerStrategy.h"
#include "../Model/Player/CheaterComputerStrategy.h"
#include "../View/PhaseObserver.h"
#include "../View/StatisticsObserver.h"

void SinglePlayerGameEngine::startGame() {
    initGame();

    startUpPhase();

    mainLoop();
}


void SinglePlayerGameEngine::initGame() {
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

void SinglePlayerGameEngine::startUpPhase() {

    auto temp = startup::order_play(state.getPlayers());

    startup::distributing_countries(state.getMap()->getCountries(), temp);
    startup::distributing_armies(temp);
    startup::placing_armies(temp);
}

void SinglePlayerGameEngine::mainLoop() {
    map_ptr map = state.getMap();
    auto players = state.getPlayers();
    state.calculateNewPercentage();

    bool isFinished = false;
    while(!isFinished) {
        for(Player* &player: players) {
            if (playerDoesNotOwnAnyCountries(player))
                continue;

            state.setPhaseState("Player " + to_string(player->getId()) + "'s turn.");
            state.finishCurrentState();

            askIfWantToChangeStrategy(player);

            player->reinforce(&state);
            player->attack(&state);

            // Check if someone won the game
            // It can only happen after an attack phase
            if(map->ownerOfAllCountries() != nullptr) {
                isFinished = true;
                break;
            }

            player->fortify(&state);
        }
    }

    GameFinishView gameFinishView;
    if (map->ownerOfAllCountries() != nullptr)
        gameFinishView.announceWinner(map->ownerOfAllCountries());
}

void SinglePlayerGameEngine::askIfWantToChangeStrategy(Player *player) {
    std::cout << "Do you want to change strategy? (yes/no)" << std::endl;
    std::string input;
    std::cin >> input;

    if (input == "yes") {
        std::cout << "which type? (human, attack, defence)" << std::endl;
        std::cin >> input;

        if (input == "human")
            player->setStrategy(new HumanStrategy());
        else if (input == "attack")
            player->setStrategy(new AggressiveComputerStrategy());
        else if (input == "cheater")
            player->setStrategy(new CheaterComputerStrategy());
        else if (input == "random")
            player->setStrategy(new RandomComputerStrategy());
        else
            player->setStrategy(new BenevolentComputerStrategy());
    }
}
