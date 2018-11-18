#include "PhaseView.h"
#include "../Controller/GameEngine.h"


void PhaseView::update(std::string m){
    viewStream << m << endl;

}

PhaseView::PhaseView(){
    viewStream.open("PhaseView.txt");
}

void PhaseView::clear(){
    viewStream.close();
    viewStream.open("PhaseView.txt", std::ofstream::out|  std::ofstream::trunc);
}

