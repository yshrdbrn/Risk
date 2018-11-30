//
// Created by Yashar Dabiran on 2018-10-29.
//

#ifndef RISKGAME_GAMESETUPVIEW_H
#define RISKGAME_GAMESETUPVIEW_H

#include <string>
#include <vector>

class GameSetupView {
private:

public:
    /**
     * Shows the message to the console
     * @param error the message to be shown
     */
    void showError(std::string error);

    /**
     * Asks the user to choose one of the map file names and returns the index of the chosen file name.
     * It is guaranteed that the return value is valid (is in the range of the vector)
     * @param fileNames vector of all the map file names
     * @return index of the chosen map
     */
    int promptUserToChooseMapFile(std::vector<std::string> fileNames);

    /**
     * Asks the user to choose the number of players.
     * It is guaranteed that the number of players is between minPlayers and maxPlayers
     * @param minPlayers minimum number of players
     * @param maxPlayers maximum number of players
     * @return number of players
     */
    int promptUserToChooseNumberOfPlayers(int minPlayers, int maxPlayers);

    int chooseNumberOfMaps();

    int chooseNumberOfGames();

    int chooseMaximumNumberOfTurns();

    std::vector<std::string> getPlayerTypes();

    std::string chooseGameType();
};


#endif //RISKGAME_GAMESETUPVIEW_H
