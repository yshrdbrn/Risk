//
// Created by Yashar Dabiran on 2018-11-14.
//

#ifndef RISKGAME_AGGRESSIVECOMPUTERSTRATEGY_H
#define RISKGAME_AGGRESSIVECOMPUTERSTRATEGY_H

#include <unordered_map>
#include "Strategy.h"

class AggressiveComputerStrategy: public Strategy {
private:
    /**
     * This function attacks to an enemy neighbor of the country given
     * @param country the country to check the neighbors of
     * @param state of the game to change
     */
    void attackANeighborCountry(country_ptr country, State *state);

public:
    void performAttack(Player *player, State *state) override;

    void performFortify(Player *player, State *state) override;

    void performReinforce(Player *player, State *state) override;

    int whichCountryToPlaceOneArmyOn(Player *player) override;
};


#endif //RISKGAME_AGGRESSIVECOMPUTERSTRATEGY_H
