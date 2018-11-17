//
// Created by Yashar Dabiran on 2018-11-14.
//

#ifndef RISKGAME_BENEVOLENTCOMPUTERSTRATEGY_H
#define RISKGAME_BENEVOLENTCOMPUTERSTRATEGY_H

#include "Strategy.h"

class BenevolentComputerStrategy: public Strategy {
public:
    std::string performAttack(Player*) override;

    std::string performFortify(Player*) override;

    std::string performReinforce(Player*) override;
};


#endif //RISKGAME_BENEVOLENTCOMPUTERSTRATEGY_H
