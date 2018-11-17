//
// Created by Yashar Dabiran on 2018-11-14.
//

#ifndef RISKGAME_BENEVOLENTCOMPUTERSTRATEGY_H
#define RISKGAME_BENEVOLENTCOMPUTERSTRATEGY_H

#include "Strategy.h"

class BenevolentComputerStrategy: public Strategy {
public:
    void performAttack(Player *player) override;

    void performFortify(Player *player) override;

    void performReinforce(Player *player) override;
};


#endif //RISKGAME_BENEVOLENTCOMPUTERSTRATEGY_H
