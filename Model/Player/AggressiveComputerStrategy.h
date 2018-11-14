//
// Created by Yashar Dabiran on 2018-11-14.
//

#ifndef RISKGAME_AGGRESSIVECOMPUTERSTRATEGY_H
#define RISKGAME_AGGRESSIVECOMPUTERSTRATEGY_H

#include "Strategy.h"

class AggressiveComputerStrategy: public Strategy {
public:
    void performAttack(std::vector<country_ptr> &countries, Hand &hand) override;

    void performFortify(std::vector<country_ptr> &countries, Hand &hand) override;

    void performReinforce(std::vector<country_ptr> &countries, Hand &hand, Player *player) override;
};


#endif //RISKGAME_AGGRESSIVECOMPUTERSTRATEGY_H
