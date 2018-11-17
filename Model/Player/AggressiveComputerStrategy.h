//
// Created by Yashar Dabiran on 2018-11-14.
//

#ifndef RISKGAME_AGGRESSIVECOMPUTERSTRATEGY_H
#define RISKGAME_AGGRESSIVECOMPUTERSTRATEGY_H

#include "Strategy.h"

class AggressiveComputerStrategy: public Strategy {
public:
    std::string performAttack(Player*) override;

    std::string performFortify(Player*) override;

    std::string performReinforce(Player*) override;
};


#endif //RISKGAME_AGGRESSIVECOMPUTERSTRATEGY_H
