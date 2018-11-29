//
// Created by Yashar Dabiran on 2018-11-29.
//

#ifndef RISKGAME_CHEATERCOMPUTERSTRATEGY_H
#define RISKGAME_CHEATERCOMPUTERSTRATEGY_H

#include "Strategy.h"

class CheaterComputerStrategy: public Strategy {
public:
    void performAttack(Player *player, State *state) override;

    void performFortify(Player *player, State *state) override;

    void performReinforce(Player *player, State *state) override;

    int whichCountryToPlaceOneArmyOn(Player *player) override;
};


#endif //RISKGAME_CHEATERCOMPUTERSTRATEGY_H
