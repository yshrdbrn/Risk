//
// Created by Yashar Dabiran on 2018-11-20.
//

#include "Observable.h"
#include "../View/Observer.h"

void Observable::attach(Observer *observer) {
    observers.push_back(observer);
}

void Observable::detach(Observer *observer) {
    for (auto it = observers.begin(); it != observers.end(); it++) {
        if (*it == observer) {
            observers.erase(it);
            break;
        }
    }
}

void Observable::notify() {
    for (auto observer: observers)
        observer->update();
}

Observable::~Observable() {
    for (int i = 0; i < observers.size(); i++) {
        delete observers[i];
    }
};