#include "Subject.h"


void Subject::registerObserver(Observer *observer){
      observers->push_back(observer);
}

  
void Subject::removeObserver(Observer *observer){
    observers->remove(observer);
}

void Subject::notifyObservers(){
     std::list<Observer*>::iterator i;
        for(i=observers->begin() ; i != observers->end() ; i++){
            (*i)->update();
        }
}

Subject::Subject(){
    observers = new std::list<Observer*>;
}

Subject::~Subject(){
    delete observers;
    }
