//
// Created by Yashar Dabiran on 2018-11-14.
//

#ifndef RISKGAME_STRATEGY_H
#define RISKGAME_STRATEGY_H

#include <vector>
#include "../Map/country.h"

typedef std::shared_ptr<Country> country_ptr;

class Strategy {
protected:
    int giveArmiesToPlayer(Player *player);
public:
    virtual void performAttack(Player*) = 0;
    virtual void performFortify(Player*) = 0;
    virtual void performReinforce(Player*) = 0;
};

#endif //RISKGAME_STRATEGY_H
