#include "PhaseView.h"
#include "../Controller/GameEngine.h"
#include "../Model/GameState/PhaseState.h"


void PhaseView::update(){
    
    cout<<"View1:" <<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout<<"Player"<< _subject->getPlayer()->getId() <<"'s turn:" <<endl ;
    if(_subject->getPhase() != "")
    cout << _subject->getPhase() << " phase" <<endl;
    if(_subject->getDescription() != "")
    cout<<_subject->getDescription()<<endl;

    cout << "--------------------------------------------------------------------------------"<<endl;

}

PhaseView::PhaseView(PhaseState* ps){
    _subject = ps;
    ps->registerObserver(this);
}

