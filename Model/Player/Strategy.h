//
// Created by Yashar Dabiran on 2018-11-14.
//

#ifndef RISKGAME_STRATEGY_H
#define RISKGAME_STRATEGY_H

#include <vector>
#include "../Map/country.h"

typedef std::shared_ptr<Country> country_ptr;

class Strategy {
protected:
    int giveArmiesToPlayer(Player *player);
public:
<<<<<<< HEAD
    virtual std::string performAttack(Player*) = 0;
    virtual std::string performFortify(Player*) = 0;
    virtual std::string performReinforce(Player*) = 0;
=======
    virtual void performAttack(Player *player) = 0;
    virtual void performFortify(Player *player) = 0;
    virtual void performReinforce(Player *player) = 0;
>>>>>>> f9f1e930e70cdc96045ddea0c43b41dc19eab019
};

#endif //RISKGAME_STRATEGY_H
