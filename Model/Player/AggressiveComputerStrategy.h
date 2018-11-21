//
// Created by Yashar Dabiran on 2018-11-14.
//

#ifndef RISKGAME_AGGRESSIVECOMPUTERSTRATEGY_H
#define RISKGAME_AGGRESSIVECOMPUTERSTRATEGY_H

#include <unordered_map>
#include "Strategy.h"

class AggressiveComputerStrategy: public Strategy {
private:
    /**
     * This function attacks to an enemy neighbor of the country given
     * @param country the country to check the neighbors of
     * @param state of the game to change
     */
    void attackANeighborCountry(country_ptr country, State *state);

    /**
     * This country will perform the attack from the attacking country to the defending country
     * @param attackingCountry the country we want to attack from
     * @param defendingCountry the country that is defending
     * @param state of the game to change
     */
    void attackFromCountryToCountry(country_ptr attackingCountry, country_ptr defendingCountry, State *state);

    /**
     * Used in Fortify
     * It will traverse the graph to get the components of the graph a player owns
     * @param node current node that we are traversing
     * @param mark a map to mark the vertices we've been to
     * @param nodesInComponent a vector containing all the vertices we've been at in the component
     */
    void dfs(country_ptr node, std::unordered_map<std::string, bool> &mark, std::vector<country_ptr> &nodesInComponent);

    /**
     * Checks if there is any neighbor enemy country for the country given
     * @param countryPtr the country to check the neighbors of
     * @return if there is an enemy neighbor country
     */
    bool isThereACountryLeftToAttack(country_ptr countryPtr);

public:
    void performAttack(Player *player, State *state) override;

    void performFortify(Player *player, State *state) override;

    void performReinforce(Player *player, State *state) override;

    int whichCountryToPlaceOneArmyOn(Player *player) override;
};


#endif //RISKGAME_AGGRESSIVECOMPUTERSTRATEGY_H
