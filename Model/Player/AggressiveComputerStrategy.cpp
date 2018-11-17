//
// Created by Yashar Dabiran on 2018-11-14.
//

#include <cmath>
#include <vector>
#include <algorithm>
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
