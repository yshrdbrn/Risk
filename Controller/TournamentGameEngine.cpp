//
// Created by Yashar Dabiran on 2018-11-29.
//

#include <vector>
#include <iostream>
#include <string>
#include "TournamentGameEngine.h"
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

void TournamentGameEngine::startGame() {
    // Set the observers
    state.attach(new PhaseObserver(&state));
    state.attach(new StatisticsObserver(&state));

    getTournamentInfo();

    printTournamentInfo();

    for (std::string &map: mapNames) {
        initGame(map);

        startUpPhase();

        mainLoop();
    }
}

void TournamentGameEngine::mainLoop() {

}

void TournamentGameEngine::initGame(std::string mapName) {
    MapLoader mapLoader;

    state.setMap(mapLoader.createMapWithFileName(mapName);

    // Create the Deck
    state.setDeck(new Deck(state.getMap()->numberOfCountries()));

    // Create the players
    std::vector<Player *> players;
    for (int i = 0; i < playerTypes.size(); i++) {
        std::string type = playerTypes[i];
        if (type == "attacker")
            players.push_back(new Player(i + 1, new AggressiveComputerStrategy()));
        else if (type == "cheater")
            players.push_back(new Player(i + 1, new CheaterComputerStrategy()));
        else if (type == "random")
            players.push_back(new Player(i + 1, new RandomComputerStrategy()));
        else
            players.push_back(new Player(i + 1, new BenevolentComputerStrategy()));
    }

    state.setPlayers(players);
}

void TournamentGameEngine::getTournamentInfo() {
    // Get the object of all valid maps
    MapLoader mapLoader;
    std::vector<std::string> allMaps = mapLoader.getListOfAllMapFiles();
    // Filter out the wrong maps
    for(int i = 0; i < allMaps.size(); i++) {
        try {
            auto map = mapLoader.createMapWithFileName(mapNames[i]);
            mapNames.push_back(allMaps[i]);
        } catch (RiskException &e) {
            // Just catch the exception
        }
    }

    GameSetupView gameSetupView;
    numberOfMaps = gameSetupView.chooseNumberOfMaps();
    numberOfGames = gameSetupView.chooseNumberOfGames();
    maxNumberOfTurns = gameSetupView.chooseMaximumNumberOfTurns();
    playerTypes = gameSetupView.getPlayerTypes();
}

void TournamentGameEngine::printTournamentInfo() {
    // TODO
}
