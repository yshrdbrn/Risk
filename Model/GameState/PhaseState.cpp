#include "PhaseState.h"
#include <iostream>
   

    void PhaseState::setPhase(std::string p){
        phase = p;
        notifyObservers();
    }

   
    std::string PhaseState::getPhase(){
        return phase;
    }

    Player * PhaseState::getPlayer(){
        return player;
    }


    void PhaseState::setPlayer(Player* p){
        player = p;
        notifyObservers();
    }

    void PhaseState::setDescription(std::string m){
        description = m;
        notifyObservers();

    };
    std::string PhaseState::getDescription(){
        return description;
    }

    PhaseState::PhaseState(){
        phase = "";
        description= "";
    }

    void PhaseState::clear() {
        phase = "";
        description = "";
        notifyObservers();
    }