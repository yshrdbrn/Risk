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
    void showError(std::string error);

    int promptUserToChooseMapFile(std::vector<std::string> fileNames);

    int promptUserToChooseNumberOfPlayers(int minPlayers, int maxPlayers);
};


#endif //RISKGAME_GAMESETUPVIEW_H
