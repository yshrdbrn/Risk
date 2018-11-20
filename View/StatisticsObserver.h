//
// Created by Yashar Dabiran on 2018-11-20.
//

#ifndef RISKGAME_STATISTICSOBSERVER_H
#define RISKGAME_STATISTICSOBSERVER_H

#include "Observer.h"
#include "../Controller/State.h"

class StatisticsObserver: public Observer {
private:
    State *state;
};


#endif //RISKGAME_STATISTICSOBSERVER_H
