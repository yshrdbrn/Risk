//
// Created by Yashar Dabiran on 2018-10-29.
//

#include <vector>
#include "GameEngine.h"
#include "../View/GameSetupView.h"
#include "../Model/Map/riskException.h"

void GameEngine::startGame() {
    MapLoader mapLoader;
    GameSetupView gameSetupView;
    std::vector<std::string> mapNames = mapLoader.getListOfAllMapFiles();

    while(true) {
        try {
            int mapNumber = gameSetupView.promptUserToChooseMapFile(mapNames);
            map = mapLoader.createMapWithFileName(mapNames[mapNumber]);
            break;
        } catch (RiskException &e) {
            gameSetupView.showError(e.what());
        }
    }

    int numberOfPlayers = gameSetupView.promptUserToChooseNumberOfPlayers(MIN_PLAYERS, MAX_PLAYERS);

    for (int i = 0; i < numberOfPlayers; i++)
        players.push_back(new Player());
}

GameEngine::~GameEngine() {
    for (int i = 0; i < players.size(); i++)
        delete players[i];
}
