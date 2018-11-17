//
// Created by Yashar Dabiran on 2018-11-14.
//

#ifndef RISKGAME_BENEVOLENTCOMPUTERSTRATEGY_H
#define RISKGAME_BENEVOLENTCOMPUTERSTRATEGY_H

#include "Strategy.h"

class BenevolentComputerStrategy: public Strategy {
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


#endif //RISKGAME_BENEVOLENTCOMPUTERSTRATEGY_H
