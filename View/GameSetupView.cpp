//
// Created by Yashar Dabiran on 2018-10-29.
//

#include <iostream>
#include <string>
#include <vector>
#include <exception>
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
    std::cout << "Error: " + error << std::endl;
}

int GameSetupView::chooseNumberOfMaps() {
    int numberOfMaps = 0;
    while (true) {
        std::cout << "Enter number of maps (between 1 and 5):";
        std::cin >> numberOfMaps;
        if (numberOfMaps >= 1 && numberOfMaps <= 5)
            break;

        // If number not valid
        std::cout << "Number not valid." << "\n\n";
    }

    return numberOfMaps;
}

int GameSetupView::chooseNumberOfGames() {
    int numberOfGames = 0;
    while (true) {
        std::cout << "Enter number of games (between 1 and 5):";
        std::cin >> numberOfGames;
        if (numberOfGames >= 1 && numberOfGames <= 5)
            break;

        // If number not valid
        std::cout << "Number not valid." << "\n\n";
    }

    return numberOfGames;
}

int GameSetupView::chooseMaximumNumberOfTurns() {
    int numberOfTurns = 0;
    while (true) {
        std::cout << "Enter number of turns (between 10 and 50):";
        std::cin >> numberOfTurns;
        if (numberOfTurns >= 10 && numberOfTurns <= 50)
            break;

        // If number not valid
        std::cout << "Number not valid." << "\n\n";
    }

    return numberOfTurns;
}

std::vector<std::string> GameSetupView::getPlayerTypes() {
    int numberOfPlayers = 0;
    while (true) {
        std::cout << "Enter number of maps (between 2 and 4):";
        std::cin >> numberOfPlayers;
        if (numberOfPlayers >= 2 && numberOfPlayers <= 4)
            break;

        // If number not valid
        std::cout << "Number not valid." << "\n\n";
    }

    std::vector<std::string> playerTypes;
    for (int i = 0; i < numberOfPlayers; i++) {
        std::cout << "Enter the type number of player " + std::to_string(i + 1) + ": " << std::endl;
        std::cout << "\t1) Aggressive" << std::endl;
        std::cout << "\t2) Benevolent" << std::endl;
        std::cout << "\t3) Random" << std::endl;
        std::cout << "\t4) Cheater" << std::endl;

        int choice;
        while (true) {
            std::cin >> choice;
            if (choice >= 1 && choice <= 4)
                break;
            // If number not valid
            std::cout << "Number not valid." << "\n\n";
        }

        switch (choice) {
            case 1:
                playerTypes.emplace_back("attacker");
                break;
            case 2:
                playerTypes.emplace_back("defender");
                break;
            case 3:
                playerTypes.emplace_back("random");
                break;
            case 4:
                playerTypes.emplace_back("cheater");
                break;
            default:
                throw std::exception();
        }
    }

    return playerTypes;
}
