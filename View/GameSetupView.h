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
    std::string promptUserToChooseMapFile(std::vector<std::string> fileNames);

    int promptUserToChooseNumberOfPlayers();
};


#endif //RISKGAME_GAMESETUPVIEW_H
