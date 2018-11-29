//
// Created by Yashar Dabiran on 2018-11-14.
//

#include <cmath>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include "AggressiveComputerStrategy.h"
#include "Player.h"
#include "../Map/continent.h"
#include "../../Controller/State.h"

void AggressiveComputerStrategy::performAttack(Player *player, State *state) {
    state->setPhaseState("Beginning attacking phase... ");

    auto countries = player->getCountries();

    // Finding the country if the maximum number of armies
    country_ptr maxCountry = countries[0];
    for (int i = 1; i < countries.size(); i++) {
        if (countries[i]->getNumOfArmies() > maxCountry->getNumOfArmies())
            maxCountry = countries[i];
    }

    // While there is a country to attack and the attacking country has more than one army
    while (isThereACountryLeftToAttack(maxCountry) && maxCountry->getNumOfArmies() > 1) {
        attackANeighborCountry(maxCountry, state);
    }

    state->finishCurrentState();
}

void AggressiveComputerStrategy::attackANeighborCountry(country_ptr country, State *state) {
    auto neighbors = country->getNeighbors();
    // Find an enemy neighbor
    for (int i = 0; i < neighbors.size(); i++) {
        if (country->getOwner()->getId() != neighbors[i]->getOwner()->getId()) {
            attackFromCountryToCountry(country, neighbors[i], state);
            break;
        }
    }
}




void AggressiveComputerStrategy::performFortify(Player *player, State *state) {
    state->setPhaseState("Beginning Fortify Phase... ");

    auto countries = player->getCountries();
    // mark map for DFS
    std::unordered_map<std::string, bool> mark;
    for (const country_ptr &countryPtr: countries)
        mark[countryPtr->getName()] = false;

    std::vector<country_ptr> nodesInComponent;
    // DFS on all of the countries owned by player
    for (int i = 0; i < countries.size(); i++) {
        if (!mark[countries[i]->getName()]) {
            // For every component in the graph of countries owned by player
            nodesInComponent.clear();
            dfs(countries[i], mark, nodesInComponent);

            // Find the country with an enemy neighbor
            country_ptr countryWithAnEnemyNeighbor = nodesInComponent[0];
            for (int i = 0; i < nodesInComponent.size(); i++) {
                if (isThereACountryLeftToAttack(nodesInComponent[i])) {
                    countryWithAnEnemyNeighbor = nodesInComponent[i];
                    break;
                }
            }

            // Add all of armies in the component to one country with an enemy neighbor
            for (int i = 0; i < nodesInComponent.size(); i++) {
                int remainder = nodesInComponent[i]->getNumOfArmies() - 1;
                countryWithAnEnemyNeighbor->addNumOfArmies(remainder);
                nodesInComponent[i]->removeNumOfArmies(remainder);

                if (remainder != 0)
                    state->addToPhaseState("Moved " + std::to_string(remainder) + " armies from " +
                          nodesInComponent[i]->getName() + " to " + countryWithAnEnemyNeighbor->getName());
            }
        }
    }

    state->finishCurrentState();
}



void AggressiveComputerStrategy::performReinforce(Player *player, State *state) {
    state->setPhaseState("Beginning Reinforce Phase... ");

    int armies = giveArmiesToPlayer(player);
    auto countries = player->getCountries();

    state->addToPhaseState("Player " + std::to_string(player->getId()) + " has " + std::to_string(armies) + " new armies to place.");

    // Finding the country with the maximum number of armies
    country_ptr maxCountry = countries[0];
    for (int i = 1; i < countries.size(); i++) {
        if (countries[i]->getNumOfArmies() > maxCountry->getNumOfArmies())
            maxCountry = countries[i];
    }

    // Give all of the new armies to the found country
    maxCountry->addNumOfArmies(armies);
    state->addToPhaseState("Added " + std::to_string(armies) + " armies to " + maxCountry->getName());

    state->finishCurrentState();
}

int AggressiveComputerStrategy::whichCountryToPlaceOneArmyOn(Player *player) {
    auto countries = player->getCountries();

    // Return the index of the country with 0 armies
    for (int i = 0; i < countries.size(); i++) {
        if (countries[i]->getNumOfArmies() == 0)
            return i;
    }

    // STRATEGY:
    // Find the index of the country with the maximum number of armies
    int maxCountryArmies = countries[0]->getNumOfArmies();
    int maxCountryIndex = 0;
    for(int i = 1; i < countries.size(); i++) {
        if (countries[i]->getNumOfArmies() > maxCountryArmies) {
            maxCountryArmies = countries[i]->getNumOfArmies();
            maxCountryIndex = i;
        }
    }

    return maxCountryIndex;
}
