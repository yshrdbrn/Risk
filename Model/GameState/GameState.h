#pragma once
#include <iostream>
#include "Subject.h"
#include "../Player/Player.h"
#include "../Map/map.h"

class Observer;

typedef std::unique_ptr<Map> map_ptr;

class GameState : public Subject 
{
private:
    std::string phase;
    Player * player;
    std::string phaseDescription;
    map_ptr map;
    std::vector<Observer*> observers;

public:

    //GameState(map_ptr);

    ~GameState(){
    }

    void setPhase(std::string);
    std::string getPhase();

    Player * getPlayer();
    void setPlayer(Player*);

    void setPhaseDescription(std::string);
    std::string getPhaseDescription();

    map_ptr getMap();
    void setMap(map_ptr);

    virtual void registerObserver(Observer *observer) override ;

    //virtual void removeObserver(Observer *observer) override;

    virtual void notifyObservers() override;

};