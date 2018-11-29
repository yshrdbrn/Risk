//
// Created by Yashar Dabiran on 2018-11-20.
//

#ifndef RISKGAME_STATISTICSOBSERVER_H
#define RISKGAME_STATISTICSOBSERVER_H

#include <vector>
#include "Observer.h"
#include "../Controller/State.h"

class StatisticsObserver: public Observer {
private:
    State *state;
    // Current state of the observer
    std::vector<int> dominationPercentage;

    /**
     * Prints the bar graph based on the percentages in the dominationPercentage vector
     * It will print one * for each 4%
     * It prints the numbers in RED
     */
    void printBarGraph();
public:
    ~StatisticsObserver();

    explicit StatisticsObserver(State *state);

    void update() override;
};


#endif //RISKGAME_STATISTICSOBSERVER_H
