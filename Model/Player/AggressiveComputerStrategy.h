//
// Created by Yashar Dabiran on 2018-11-14.
//

#ifndef RISKGAME_AGGRESSIVECOMPUTERSTRATEGY_H
#define RISKGAME_AGGRESSIVECOMPUTERSTRATEGY_H

#include <unordered_map>
#include "Strategy.h"

class AggressiveComputerStrategy: public Strategy {
private:
    void attackNeighborCountry(country_ptr country);

    void attackFromCountryToCountry(country_ptr attackingCountry, country_ptr defendingCountry);

    void dfs(country_ptr node, std::unordered_map<std::string, bool> &mark, std::vector<country_ptr> &nodesInComponent);

public:
<<<<<<< HEAD
    std::string performAttack(Player*) override;

    std::string performFortify(Player*) override;

    std::string performReinforce(Player*) override;
=======
    void performAttack(Player *player) override;

    void performFortify(Player *player) override;

    void performReinforce(Player *player) override;
>>>>>>> f9f1e930e70cdc96045ddea0c43b41dc19eab019
};


#endif //RISKGAME_AGGRESSIVECOMPUTERSTRATEGY_H
