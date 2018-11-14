//
// Created by Yashar Dabiran on 2018-11-14.
//

#ifndef RISKGAME_BENEVOLENTCOMPUTERSTRATEGY_H
#define RISKGAME_BENEVOLENTCOMPUTERSTRATEGY_H

#include "Strategy.h"

class BenevolentComputerStrategy: public Strategy {
public:
    void performAttack(std::vector<country_ptr> &countries, Hand &hand) override;

    void performFortify(std::vector<country_ptr> &countries, Hand &hand) override;

    void performReinforce(std::vector<country_ptr> &countries, Hand &hand, Player *player) override;
};


#endif //RISKGAME_BENEVOLENTCOMPUTERSTRATEGY_H
