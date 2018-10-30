//
// Created by Yashar Dabiran on 2018-10-29.
//

#include <iostream>
#include <string>
#include "GameSetupView.h"

int GameSetupView::promptUserToChooseMapFile(std::vector<std::string> fileNames) {
    std::cout << "Choose one of the maps below:" << std::endl;
    for (int i = 0; i < fileNames.size(); i++)
        std::cout << "\t" + std::to_string(i+1) + ") " + fileNames[i] << std::endl;

    int index;
    while (true) {
        std::cin >> index;
        if (index >= 1 && index <= fileNames.size())
            break;

        //Number not valid
        std::cout << "Number not valid. enter the number again: ";
    }

    index--;
    return index;
}

int GameSetupView::promptUserToChooseNumberOfPlayers(int minPlayers, int maxPlayers) {
    int numberOfPlayers = 0;
    while (true) {
        std::cout << "Enter number of players (between " + std::to_string(minPlayers) +
                    " and " + std::to_string(maxPlayers) + "): ";
        std::cin >> numberOfPlayers;
        if (numberOfPlayers >= 2 && numberOfPlayers <= 6)
            break;

        // If number not valid
        std::cout << "Number not valid." << "\n\n";
    }

    return numberOfPlayers;
}

void GameSetupView::showError(std::string error) {

}
