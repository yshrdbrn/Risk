#include "Subject.h"


void Subject::registerObserver(Observer *observer){
      observers->push_back(observer);
}

  
void Subject::removeObserver(Observer *observer){
    observers->remove(observer);
}


Subject::Subject(){
    observers = new std::list<Observer*>;
}

Subject::~Subject(){
    delete observers;
    }
