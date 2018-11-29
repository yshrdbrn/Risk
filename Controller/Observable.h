//
// Created by Yashar Dabiran on 2018-11-20.
//

#ifndef RISKGAME_OBSERVABLE_H
#define RISKGAME_OBSERVABLE_H

#include <vector>
#include "../View/Observer.h"

class Observable {
private:
    std::vector<Observer *> observers;

public:

    ~Observable();

    void attach(Observer *observer);

    void detach(Observer *observer);

    void notify();
};


#endif //RISKGAME_OBSERVABLE_H
