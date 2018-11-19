//
// Created by Yashar Dabiran on 2018-11-14.
//

#ifndef RISKGAME_HUMANSTRATEGY_H
#define RISKGAME_HUMANSTRATEGY_H

#include "Strategy.h"

class HumanStrategy: public Strategy {
public:
    void performAttack(Player *player) override;

    void performFortify(Player *player) override;

    void performReinforce(Player *player) override;

    int whichCountryToPlaceOneArmyOn(Player *player) override;
};


#endif //RISKGAME_HUMANSTRATEGY_H
