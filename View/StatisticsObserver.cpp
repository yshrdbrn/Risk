//
// Created by Yashar Dabiran on 2018-11-20.
//

#include <iostream>
#include "StatisticsObserver.h"

StatisticsObserver::StatisticsObserver(State *state) : state(state) {}

void StatisticsObserver::update() {
    std::vector<int> currentDominationPercentage = state->getDominationPercentage();

    // Check if the domination percentage is changed
    bool isChanged = false;
    if (dominationPercentage.size() != currentDominationPercentage.size()) { // Checks if the current percentage vector is empty
        isChanged = true;
    } else {
        for (int i = 0; i < dominationPercentage.size(); i++) {
            if (dominationPercentage[i] != currentDominationPercentage[i]) {
                isChanged = true;
                break;
            }
        }
    }

    if (isChanged) {
        // Copy contents of the new percentage into the current state
        dominationPercentage.clear();
        for (int i = 0; i < currentDominationPercentage.size(); i++)
            dominationPercentage.push_back(currentDominationPercentage[i]);

        // Print the graph
        printBarGraph();
    }
}

void StatisticsObserver::printBarGraph() {
    // Change the color of the text to RED
    std::cout << "\033[1;31mWorld domination graph:" << std::endl;
    for (int i = 0; i < dominationPercentage.size(); i++) {
        // Each 4% represents one *
        int numberOfStars = (dominationPercentage[i] / 4) + 1;
        std::cout << "Player " << (i + 1) << ": ";
        for (int j = 0; j < numberOfStars; j++)
            std::cout << '*';
        std::cout << " " <<  dominationPercentage[i] << '%' << std::endl;
    }
    std::cout << "\033[0m";
}
