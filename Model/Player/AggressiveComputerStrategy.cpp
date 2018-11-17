//
// Created by Yashar Dabiran on 2018-11-14.
//

#include <cmath>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "AggressiveComputerStrategy.h"
#include "Player.h"
#include "../Map/continent.h"

void AggressiveComputerStrategy::performAttack(Player *player) {
    auto countries = player->getCountries();

    // Finding the country if the maximum number of armies
    country_ptr maxCountry = countries[0];
    for (int i = 1; i < countries.size(); i++) {
        if (countries[i]->getNumOfArmies() > maxCountry->getNumOfArmies())
            maxCountry = countries[i];
    }

    while (maxCountry->getNumOfArmies() > 1) {
        attackNeighborCountry(maxCountry);
    }
}

void AggressiveComputerStrategy::attackNeighborCountry(country_ptr country) {
    auto neighbors = country->getNeighbors();
    // Find an enemy neighbor
    for (int i = 0; i < neighbors.size(); i++) {
        if (country->getOwner()->getId() != neighbors[i]->getOwner()->getId()) {
            attackFromCountryToCountry(country, neighbors[i]);
        }
    }
}

void AggressiveComputerStrategy::attackFromCountryToCountry(country_ptr attackingCountry, country_ptr defendingCountry) {
    int attackMaxDice = std::min(3, attackingCountry->getNumOfArmies() - 1);
    int defenceMaxDice = std::min(2, defendingCountry->getNumOfArmies());

    // Get the dice results
    std::vector<int> attackingDiceResult = attackingCountry->getOwner()->getDice()->diceRoll(attackMaxDice);
    std::vector<int> defendingDiceResult = defendingCountry->getOwner()->getDice()->diceRoll(defenceMaxDice);

    // Sort the dice for each player
    std::sort(attackingDiceResult.begin(), attackingDiceResult.end());
    std::sort(defendingDiceResult.begin(), defendingDiceResult.end());

    // Comparing dice Pair-wise
    for (int i = attackMaxDice - 1, j = defenceMaxDice - 1; i >= 0 && j >= 0; i--, j--) {
        if (attackingDiceResult[i] > defendingDiceResult[j])
            defendingCountry->removeNumOfArmies(1);
        else
            attackingCountry->removeNumOfArmies(1);
    }
}




void AggressiveComputerStrategy::performFortify(Player *player) {
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

            // Add all of armies in the component to one country
            for (int i = 1; i < nodesInComponent.size(); i++) {
                int remainder = nodesInComponent[i]->getNumOfArmies() - 1;
                nodesInComponent[0]->addNumOfArmies(remainder);
                nodesInComponent[i]->removeNumOfArmies(remainder);
            }
        }
    }
}

void AggressiveComputerStrategy::dfs(country_ptr node, std::unordered_map<std::string, bool> &mark,
                                     std::vector<country_ptr> &nodesInComponent) {
    mark[node->getName()] = true;
    // Add country to the list of countries in the component
    nodesInComponent.push_back(node);

    // Check its neighbors
    for (const auto &t: node->getNeighbors()) {
        if (t->getOwner()->getId() == node->getOwner()->getId() && !mark[t->getName()])
            dfs(t, mark, nodesInComponent);
    }
}



void AggressiveComputerStrategy::performReinforce(Player *player) {
    int armies = giveArmiesToPlayer(player);
    auto countries = player->getCountries();

    // TODO: Get armies from exchanging armies in hand

    // Finding the country with the maximum number of armies
    country_ptr maxCountry = countries[0];
    for (int i = 1; i < countries.size(); i++) {
        if (countries[i]->getNumOfArmies() > maxCountry->getNumOfArmies())
            maxCountry = countries[i];
    }

    // Give all of the new armies to the found country
    maxCountry->addNumOfArmies(armies);
}
