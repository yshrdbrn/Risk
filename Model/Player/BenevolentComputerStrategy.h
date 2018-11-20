//
// Created by Yashar Dabiran on 2018-11-14.
//

#ifndef RISKGAME_BENEVOLENTCOMPUTERSTRATEGY_H
#define RISKGAME_BENEVOLENTCOMPUTERSTRATEGY_H

#include <unordered_map>
#include "Strategy.h"

class BenevolentComputerStrategy: public Strategy {
private:
    void dfs(country_ptr node, std::unordered_map<std::string, bool> &mark, std::vector<country_ptr> &nodesInComponent);
public:
    void performAttack(Player *player, State *state) override;

    void performFortify(Player *player, State *state) override;

    void performReinforce(Player *player, State *state) override;

    int whichCountryToPlaceOneArmyOn(Player *player) override;
};


#endif //RISKGAME_BENEVOLENTCOMPUTERSTRATEGY_H
