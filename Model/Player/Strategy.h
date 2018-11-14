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
    virtual void performAttack(std::vector<country_ptr> &countries, Hand &hand) = 0;
    virtual void performFortify(std::vector<country_ptr> &countries, Hand &hand) = 0;
    virtual void performReinforce(std::vector<country_ptr> &countries, Hand &hand, Player *player) = 0;
};

#endif //RISKGAME_STRATEGY_H
