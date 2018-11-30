//
// Created by Yashar Dabiran on 2018-11-14.
//

#ifndef RISKGAME_STRATEGY_H
#define RISKGAME_STRATEGY_H

#include <vector>
#include <unordered_map>
#include "../Map/country.h"

typedef std::shared_ptr<Country> country_ptr;

class State;

class Strategy {
protected:
    /**
     * This will calculate how many armies each player gets at each round
     * @param player the player to give the armies to
     * @return the number of armies the player gets
     */
    int giveArmiesToPlayer(Player *player);

    /**
     * Checks if there is any neighbor enemy country for the country given
     * @param countryPtr the country to check the neighbors of
     * @return if there is an enemy neighbor country
     */
    bool isThereACountryLeftToAttack(country_ptr countryPtr);

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

public:
    virtual void performAttack(Player *player, State *state) = 0;
    virtual void performFortify(Player *player, State *state) = 0;
    virtual void performReinforce(Player *player, State *state) = 0;

    /**
     * This function gets called during the game set up
     * It will return will country to place the army in at each turn
     * @param player the player in question
     * @return the index of the country to put the army on
     */
    virtual int whichCountryToPlaceOneArmyOn(Player *player) = 0;
};

#endif //RISKGAME_STRATEGY_H
