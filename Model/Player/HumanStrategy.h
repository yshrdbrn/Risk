//
// Created by Yashar Dabiran on 2018-11-14.
//

#ifndef RISKGAME_HUMANSTRATEGY_H
#define RISKGAME_HUMANSTRATEGY_H

#include "Strategy.h"

class HumanStrategy: public Strategy {
public:
    std::string performAttack(Player *) override;

    std::string performFortify(Player*) override;

    std::string performReinforce(Player*) override;
};


#endif //RISKGAME_HUMANSTRATEGY_H
