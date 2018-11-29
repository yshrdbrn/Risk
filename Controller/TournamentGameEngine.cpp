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

    for (int i = 0; i < numberOfMaps; i++) {
        std::string map = mapNames[i];
        winners.emplace_back(vector<int>());
        for (int j = 0; j < numberOfGames; j++) {
            initGame(map);

            startUpPhase();

            int winner = mainLoop();
            winners[i].push_back(winner);
        }
    }

    printTournamentInfo();
    printResultOfTournament();
}

int TournamentGameEngine::mainLoop() {
    map_ptr map = state.getMap();
    auto players = state.getPlayers();
    state.calculateNewPercentage();

    bool isFinished = false;
    int turn = 0;
    while(!isFinished && turn < maxNumberOfTurns) {
        for(Player* &player: players) {
            if (playerDoesNotOwnAnyCountries(player))
                continue;

            state.setPhaseState("Player " + to_string(player->getId()) + "'s turn.");
            state.finishCurrentState();

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

        turn++;
    }

    if (map->ownerOfAllCountries() != nullptr)
        return map->ownerOfAllCountries()->getId() - 1;
    else
        return -1;
}

void TournamentGameEngine::initGame(std::string mapName) {
    MapLoader mapLoader;

    // Set the map
    state.setMap(mapLoader.createMapWithFileName(mapName));

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
            auto map = mapLoader.createMapWithFileName(allMaps[i]);
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
	for (int i = 0; i < this->mapNames.size(); i++) {
		cout << "M:" << mapNames[i] << ",";
	}
	cout << endl;
	
	for (int i = 0; i < this->playerTypes.size(); i++) {
		cout << "P:" << playerTypes[i] << ",";
	}
	cout << endl;

	cout << "G:" << this->numberOfGames << endl;
	cout << "D:" << this->maxNumberOfTurns << endl;
	
}

void TournamentGameEngine::printResultOfTournament() {
	for (int i = 0; i < this->numberOfGames; i++) {
		cout << "Game " << (i+1) << " ";
   }
	
	for (int i = 0; i < this->numberOfMaps; i++) {
		cout << "Map " << (i + 1) << " ";

		for (int a = 0; a < this->numberOfGames; a++) {

			if (this->winners[i][a] == -1)
				cout << " Draw";
			else
				cout << this->playerType[winners[i][a]] << " ";
		}
	}
}
