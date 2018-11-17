//
// Created by Yashar Dabiran on 2018-11-14.
//

#ifndef RISKGAME_HUMANSTRATEGY_H
#define RISKGAME_HUMANSTRATEGY_H

#include "Strategy.h"

class HumanStrategy: public Strategy {
public:
<<<<<<< HEAD
    std::string performAttack(Player *) override;

    std::string performFortify(Player*) override;

    std::string performReinforce(Player*) override;
=======
    void performAttack(Player *player) override;

    void performFortify(Player *player) override;

    void performReinforce(Player *player) override;
>>>>>>> f9f1e930e70cdc96045ddea0c43b41dc19eab019
};


#endif //RISKGAME_HUMANSTRATEGY_H
