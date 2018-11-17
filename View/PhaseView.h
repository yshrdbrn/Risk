#pragma once
#include "Observer.h"
#include "../Model/GameState/PhaseState.h"

class PhaseView : public Observer {

public:

void update() override; 
PhaseView();
PhaseView(PhaseState*);
~PhaseView();
void display();

private:
PhaseState * _subject;


};