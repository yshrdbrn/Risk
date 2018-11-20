//
// Created by Yashar Dabiran on 2018-11-20.
//

#include <iostream>
#include "PhaseObserver.h"

PhaseObserver::PhaseObserver(State *state) : state(state) {}

void PhaseObserver::update() {
    std::string curretPhaseState = state->getPhaseState();
    if (curretPhaseState != phaseState) {
        phaseState = curretPhaseState;
        std::cout << "\033[1;32m" + phaseState +"\033[0m" << std::endl;
    }
}
