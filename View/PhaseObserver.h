//
// Created by Yashar Dabiran on 2018-11-20.
//

#ifndef RISKGAME_PHASEOBSERVER_H
#define RISKGAME_PHASEOBSERVER_H

#include <string>
#include "Observer.h"
#include "../Controller/State.h"


class PhaseObserver: public Observer{
private:
    State *state;
    std::string phaseState;
public:
    PhaseObserver(State *state);

    void update() override;
};


#endif //RISKGAME_PHASEOBSERVER_H
