//
// Created by Yashar Dabiran on 2018-11-14.
//

#ifndef RISKGAME_STRATEGY_H
#define RISKGAME_STRATEGY_H

#include <vector>
#include "../Map/country.h"
#include "../Cards/Hand.h"
#include "../Dice/Dice_Roll.h"

typedef std::shared_ptr<Country> country_ptr;

class Strategy {
public:
    virtual void performAttack(Player *player) = 0;
    virtual void performFortify(Player *player) = 0;
    virtual void performReinforce(Player *player) = 0;
};

#endif //RISKGAME_STRATEGY_H
