//
// Created by Yashar Dabiran on 2018-11-14.
//

#ifndef RISKGAME_STRATEGY_H
#define RISKGAME_STRATEGY_H

#include <vector>
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
