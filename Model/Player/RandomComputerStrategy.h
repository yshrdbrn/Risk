//
// Created by Yashar Dabiran on 2018-11-29.
//

#ifndef RISKGAME_RANDOMCOMPUTERSTRATEGY_H
#define RISKGAME_RANDOMCOMPUTERSTRATEGY_H

#include "Strategy.h"


class RandomComputerStrategy: public Strategy{
private:
    /**
     * Generates a random number in the range [min, max]
     * min must be smaller than or equal to max
     * @param min minimum of the range
     * @param max maximum of the range
     * @return random number in the range between min and max
     */
    int generateRandom(int min, int max);

public:
    void performAttack(Player *player, State *state) override;

    void performFortify(Player *player, State *state) override;

    void performReinforce(Player *player, State *state) override;

    int whichCountryToPlaceOneArmyOn(Player *player) override;
};


#endif //RISKGAME_RANDOMCOMPUTERSTRATEGY_H
