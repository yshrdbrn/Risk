#include "View1.h"
#include "../Controller/GameEngine.h"
#include "../Model/GameState/GameState.h"


void View1::update(GameState* gs){

    cout<<"View1:" <<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout<<"Player"<< gs->getPlayer()->getId() <<"'s turn:" <<endl ;
    if(gs->getPhase() != "")
    cout << gs->getPhase() << " phase" <<endl;
    if(gs->getPhaseDescription() != "")
    cout<<gs->getPhaseDescription()<<endl;

    cout << "--------------------------------------------------------------------------------"<<endl;


    
    
}

