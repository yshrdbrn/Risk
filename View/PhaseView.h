#pragma once
#include "Observer.h"
#include <iostream>
#include<fstream>

class PhaseView : public Observer {

public:

void update(std::string m) override; 
PhaseView();
~PhaseView();
void openLog();
void clear();

private:
std::ofstream viewStream ;


};