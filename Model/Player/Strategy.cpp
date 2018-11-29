//
// Created by Yashar Dabiran on 2018-11-17.
//

#include "Strategy.h"
#include "Player.h"
#include "../Map/continent.h"
#include "../../Controller/State.h"

int Strategy::giveArmiesToPlayer(Player *player) {
    auto countries = player->getCountries();

    int armies = 3 ;

    //add number of armies based on number of countries owned
    if(countries.size()/3 > 3)
        armies = (countries.size()/3);


    //// Give Player extra armies if they own a continent

    // Map to mark which continents we already checked
    std::vector<std::string> continentMark;

    for (auto &country: countries) {
        auto continent = country->getContinent();
        // If we haven't checked this continent yet
        if (std::find(continentMark.begin(), continentMark.end(), continent->getName()) != continentMark.end()) {
            continentMark.push_back(continent->getName());
            if (continent->doesContinentBelongToPlayer(player))
                armies += continent->getControlValue();
        }
    }

    return armies;
}

bool Strategy::isThereACountryLeftToAttack(country_ptr countryPtr) {
    auto neighbors = countryPtr->getNeighbors();
    // Find an enemy neighbor
    for (int i = 0; i < neighbors.size(); i++) {
        if (countryPtr->getOwner()->getId() != neighbors[i]->getOwner()->getId()) {
            return true;
        }
    }

    return false;
}

void Strategy::attackFromCountryToCountry(country_ptr attackingCountry, country_ptr defendingCountry, State *state) {
    // Maximum number of dice each player can roll
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
        if (attackingDiceResult[i] > defendingDiceResult[j]) {
            defendingCountry->removeNumOfArmies(1);
            state->setPhaseState(defendingCountry->getName() + " lost one army.");
        }
        else {
            attackingCountry->removeNumOfArmies(1);
            state->setPhaseState(attackingCountry->getName() + " lost one army.");
        }
    }

    // If conquered the enemy country
    if (defendingCountry->getNumOfArmies() == 0) {
        state->addToPhaseState("Player " + std::to_string(attackingCountry->getOwner()->getId()) + " got the country " + defendingCountry->getName());
        state->transferCountryOwnership(defendingCountry, defendingCountry->getOwner(), attackingCountry->getOwner());
        // Move one army to the conquered country
        attackingCountry->removeNumOfArmies(1);
        defendingCountry->incrementArmies(1);
    }
}

void Strategy::dfs(country_ptr node, std::unordered_map<std::string, bool> &mark,
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
