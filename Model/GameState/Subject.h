#ifndef OBSERVER_PATTERN_SUBJECT_HPP
#define OBSERVER_PATTERN_SUBJECT_HPP

#include "../../View/Observer.h"
#include <list>


/**
 * Interface for the Subject
 */
class Subject {

public:


    void registerObserver(Observer *observer);

  
    void removeObserver(Observer *observer);


    virtual void notifyObservers() = 0;

    ~Subject();

    Subject();

    private:
    std::list<Observer *> * observers;

};


#endif //OBSERVER_PATTERN_SUBJECT_HPP