//
// Created by Yashar Dabiran on 2018-11-14.
//

#ifndef RISKGAME_AGGRESSIVECOMPUTERSTRATEGY_H
#define RISKGAME_AGGRESSIVECOMPUTERSTRATEGY_H

#include "Strategy.h"

class AggressiveComputerStrategy: public Strategy {
private:
    void attackNeighborCountry(country_ptr country);

    void attackFromCountryToCountry(country_ptr attackingCountry, country_ptr defendingCountry);

public:
    void performAttack(Player *player) override;

    void performFortify(Player *player) override;

    void performReinforce(Player *player) override;
};


#endif //RISKGAME_AGGRESSIVECOMPUTERSTRATEGY_H
