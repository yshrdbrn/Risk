#include "GameState.h"
#include <iostream>
#include "Subject.h"
#include "../Player/Player.h"
#include "../Map/map.h"
#include "../../View/Observer.h"
    
   /* GameState::GameState(map_ptr map){
        map = map;
    }*/


    void GameState::setPhase(std::string p){
        phase = p;
        notifyObservers();
    }

    std::string GameState::getPhase(){
        return phase;
    }

    Player * GameState::getPlayer(){
        return player;
    }


    void GameState::setPlayer(Player* p){
        player = p;
        notifyObservers();
    }

    void GameState::setPhaseDescription(std::string m){
        phaseDescription = m;
        notifyObservers();

    };
    std::string GameState::getPhaseDescription(){
        return phaseDescription;
    }

   /* map_ptr GameState::getMap(){
        return map;
    }*/
    /*void GameState::setMap(map_ptr map){
        map = map;
        notifyObservers();
    }*/

    void GameState::registerObserver(Observer *observer){
        observers.push_back(observer);
        
    }

    //void GameState::removeObserver(Observer *observer){
     //   observers.erase(observer);
    //}

    void GameState::notifyObservers() {
        std::vector<Observer*>::iterator i;
        for(i=observers.begin() ; i != observers.end() ; i++){
            (*i)->update(this);
        }
    }