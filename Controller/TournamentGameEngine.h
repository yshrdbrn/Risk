//
// Created by Yashar Dabiran on 2018-11-29.
//

#ifndef RISKGAME_TOURNAMENTGAMEENGINE_H
#define RISKGAME_TOURNAMENTGAMEENGINE_H

#include <vector>
#include <string>
#include "GameEngine.h"
#include "../Model/Maploader/mapLoader.h"

class TournamentGameEngine: public GameEngine {
private:
    std::vector<std::string> playerTypes;
    std::vector<std::string> mapNames;
    int numberOfMaps;
    int numberOfGames;
    int maxNumberOfTurns;

    void getTournamentInfo();

    void printTournamentInfo();

protected:
    void mainLoop() override;

    void initGame(std::string mapName);

public:
    void startGame() override;
};


#endif //RISKGAME_TOURNAMENTGAMEENGINE_H
