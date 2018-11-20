//
// Created by Yashar Dabiran on 2018-11-14.
//
#include <vector>
#include <algorithm>
#include "Player.h"
#include "../Map/country.h"
#include "../../Controller/State.h"

#include "BenevolentComputerStrategy.h"

void BenevolentComputerStrategy::performAttack(Player *player, State *state) {
    state->setPhaseState("Beginning attacking phase... ");
    // Do nothing here
}

void BenevolentComputerStrategy::performFortify(Player *player, State *state) {
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

            //// Normalize armies in the countries of the component

            // Sort the countries using their army size
            std::vector<pair<int, country_ptr>> minArmyCountries;
            for (auto &country : nodesInComponent)
                minArmyCountries.push_back(std::make_pair(country->getNumOfArmies(), country));
            std::sort(minArmyCountries.begin(), minArmyCountries.end());

            // while difference of armies in min country and max country is bigger than 1
            // move an army from the max country to the min country
            while (minArmyCountries[minArmyCountries.size() - 1].first -  minArmyCountries[0].first > 1) {
                state->setPhaseState("Moved one army from " + minArmyCountries[minArmyCountries.size() - 1].second->getName() +
                                    " To " + minArmyCountries[0].second->getName());

                minArmyCountries[0].second->addNumOfArmies(1);
                minArmyCountries[0].first++;
                minArmyCountries[minArmyCountries.size() - 1].second->removeNumOfArmies(1);
                minArmyCountries[minArmyCountries.size() - 1].first++;
                std::sort(minArmyCountries.begin(), minArmyCountries.end());
            }
        }
    }
}

void BenevolentComputerStrategy::dfs(country_ptr node, std::unordered_map<std::string, bool> &mark,
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

void BenevolentComputerStrategy::performReinforce(Player *player, State *state) {
    state->setPhaseState("Beginning Reinforce Phase... ");
    
    int armies = giveArmiesToPlayer(player);
    auto countries = player->getCountries();
    // TODO: Get armies from exchanging armies in hand

    state->setPhaseState("Player " + std::to_string(player->getId()) + " has " + std::to_string(armies) + " new armies to place.");

    // Sort the countries using their army size
    std::vector<pair<int, country_ptr>> minArmyCountries;
    for (auto &country : countries)
        minArmyCountries.push_back(std::make_pair(country->getNumOfArmies(), country));
    std::sort(minArmyCountries.begin(), minArmyCountries.end());

    // Add army to the minimum country, then sort the array again
    while (armies > 0) {
        state->setPhaseState("Added one army to " + minArmyCountries[0].second->getName());

        minArmyCountries[0].second->addNumOfArmies(1);
        armies--;
        minArmyCountries[0].first++;
        std::sort(minArmyCountries.begin(), minArmyCountries.end());
    }
}

int BenevolentComputerStrategy::whichCountryToPlaceOneArmyOn(Player *player) {
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
