//
// Created by Yashar Dabiran on 2018-11-20.
//

#ifndef RISKGAME_OBSERVER_H
#define RISKGAME_OBSERVER_H

#include <string>

class Observer {
public:
    virtual ~Observer() = default;

    virtual void update() = 0;
};


#endif //RISKGAME_OBSERVER_H
