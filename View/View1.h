#pragma once
#include "Observer.h"

class View1 : public Observer {

public:

void update(GameState*) override ; 
void displayGraph();

};