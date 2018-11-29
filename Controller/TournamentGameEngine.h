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

    /**
     * This 2D array will have the winners of the tournament games
     * Each cell will be the index of the winner player, or -1 if it's a draw
     */
    std::vector<std::vector<int>> winners;

    /**
     * Get the tournament parameters from the user
     */
    void getTournamentInfo();

    /**
     * Prints tournament information : M, P, G, D
     */
    void printTournamentInfo();

    /**
     * Prints the table showing the results
     */
    void printResultOfTournament();

protected:
    int mainLoop();

    void initGame(std::string mapName);

public:
    void startGame() override;
};


#endif //RISKGAME_TOURNAMENTGAMEENGINE_H
