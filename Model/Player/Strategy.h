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
    int giveArmiesToPlayer(Player *player);
public:
    virtual void performAttack(Player *player, State *state) = 0;
    virtual void performFortify(Player *player, State *state) = 0;
    virtual void performReinforce(Player *player, State *state) = 0;
    virtual int whichCountryToPlaceOneArmyOn(Player *player) = 0;
};

#endif //RISKGAME_STRATEGY_H
