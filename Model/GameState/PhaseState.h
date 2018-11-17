#pragma once
#include <iostream>
#include "Subject.h"
#include "../Player/Player.h"
#include "../Map/map.h"

class PhaseState : public Subject 
{
private:
    std::string phase;
    Player * player;
    std::string description;

public:

    PhaseState();

    void setPhase(std::string);
    std::string getPhase();

    Player * getPlayer();
    void setPlayer(Player*);

    void setDescription(std::string);
    std::string getDescription();

    void clear();

};