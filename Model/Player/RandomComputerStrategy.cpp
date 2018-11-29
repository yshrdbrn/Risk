//
// Created by Yashar Dabiran on 2018-11-29.
//
#include <vector>
#include <random>
#include "Player.h"
#include "../Map/country.h"
#include "../../Controller/State.h"
#include "RandomComputerStrategy.h"

void RandomComputerStrategy::performAttack(Player *player, State *state) {
    state->setPhaseState("Beginning attacking phase... ");

    auto countries = player->getCountries();

    int n = static_cast<int>(countries.size() - 1);

    // Find a country to attack from
    country_ptr attackingCountry = nullptr;
    do {
        attackingCountry = countries[generateRandom(0, n)];
    } while (!isThereACountryLeftToAttack(attackingCountry));

    // Find all the enemy neighbors of the attacking country
    vector<country_ptr> neighbors;
    for (auto &neighbor: attackingCountry->getNeighbors()) {
        if (neighbor->getOwner()->getId() != attackingCountry->getOwner()->getId())
            neighbors.push_back(neighbor);
    }

    // Find a random neighbor out of the enemy neighbors
    int index = generateRandom(0, static_cast<int>(neighbors.size() - 1));
    country_ptr defendingCountry = attackingCountry->getNeighbors()[index];

    // Attack the defending country a random number of times
    int numberOfAttacks = generateRandom(0, attackingCountry->getNumOfArmies() - 1);
    for (int i = 0; i < numberOfAttacks && attackingCountry->getNumOfArmies() > 1; i++) {
        attackFromCountryToCountry(attackingCountry, defendingCountry, state);
    }

    state->finishCurrentState();
}

void RandomComputerStrategy::performFortify(Player *player, State *state) {
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

            // Find a random country
            country_ptr randomCountry = nodesInComponent[generateRandom(0, nodesInComponent.size() - 1)];

            // Add all of armies in the component to the random country
            for (int i = 0; i < nodesInComponent.size(); i++) {
                int remainder = nodesInComponent[i]->getNumOfArmies() - 1;
                randomCountry->addNumOfArmies(remainder);
                nodesInComponent[i]->removeNumOfArmies(remainder);

                if (remainder != 0)
                    state->addToPhaseState("Moved " + std::to_string(remainder) + " armies from " +
                                           nodesInComponent[i]->getName() + " to " + randomCountry->getName());
            }
        }
    }

    state->finishCurrentState();
}

void RandomComputerStrategy::performReinforce(Player *player, State *state) {
    state->setPhaseState("Beginning Reinforce Phase... ");

    int armies = giveArmiesToPlayer(player);
    auto countries = player->getCountries();

    state->addToPhaseState("Player " + std::to_string(player->getId()) + " has " + std::to_string(armies) + " new armies to place.");

    // Find a random country
    country_ptr randCountry = countries[generateRandom(0, static_cast<int>(countries.size() - 1))];

    // Add army to the random country
    randCountry->addNumOfArmies(armies);
    state->addToPhaseState("Added one army to " + randCountry->getName());

    state->finishCurrentState();
}

int RandomComputerStrategy::whichCountryToPlaceOneArmyOn(Player *player) {
    auto countries = player->getCountries();

    return generateRandom(0, static_cast<int>(countries.size() - 1));
}

int RandomComputerStrategy::generateRandom(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(min, max);

    return distribution(gen);
}
