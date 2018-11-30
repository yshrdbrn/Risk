//
// Created by Yashar Dabiran on 2018-11-29.
//

#include <vector>
#include <string>
#include "Player.h"
#include "../Map/country.h"
#include "../../Controller/State.h"
#include "CheaterComputerStrategy.h"

void CheaterComputerStrategy::performAttack(Player *player, State *state) {
    state->setPhaseState("Beginning attacking phase... ");

    auto countries = player->getCountries();

    for (auto &country: countries) {
        for (auto &neighbor: country->getNeighbors()) {
            if (neighbor->getOwner()->getId() != player->getId()) {
                state->addToPhaseState("Player " + std::to_string(player->getId()) + " got the country " + neighbor->getName());
                state->transferCountryOwnership(neighbor, neighbor->getOwner(), player);
                // Move one army to the conquered country
                neighbor->removeNumOfArmies(neighbor->getNumOfArmies() - 1);
            }
        }
    }

    state->finishCurrentState();
}

void CheaterComputerStrategy::performFortify(Player *player, State *state) {
    state->setPhaseState("Beginning Fortify Phase... ");

    auto countries = player->getCountries();

    for (auto &country: countries) {
        if (isThereACountryLeftToAttack(country)) {
            country->addNumOfArmies(country->getNumOfArmies());
            state->addToPhaseState("Doubled number of armies in " + country->getName()
                                   + ": Now it has " + std::to_string(country->getNumOfArmies()) + " armies.");
        }
    }

    state->finishCurrentState();
}

void CheaterComputerStrategy::performReinforce(Player *player, State *state) {
    state->setPhaseState("Beginning Reinforce Phase... ");

    auto countries = player->getCountries();

    for (auto &country: countries) {
        country->addNumOfArmies(country->getNumOfArmies());
        state->addToPhaseState("Doubled number of armies in " + country->getName()
        + ": Now it has " + std::to_string(country->getNumOfArmies()) + " armies.");
    }

    state->finishCurrentState();
}

// Same as Benevolent Strategy
int CheaterComputerStrategy::whichCountryToPlaceOneArmyOn(Player *player) {
    auto countries = player->getCountries();

    // Find the country with minimum number of armies
    int minCountryArmies = countries[0]->getNumOfArmies();
    int minCountryIndex = 0;
    for(int i = 1; i < countries.size(); i++) {
        if (countries[i]->getNumOfArmies() < minCountryArmies) {
            minCountryArmies = countries[i]->getNumOfArmies();
            minCountryIndex = i;
        }
    }

    return minCountryIndex;
}
