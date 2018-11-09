#include <iostream>
#include "Deck.h"
#include "Hand.h"
#include "random"
#include "../Player/Player.h"

using namespace std;

int main() {
	Deck aDeck(43);   //initiating a Deck object
	Hand myHand;      //initiating a Hand object
	
	cout << aDeck.getTotalCards() << endl;  //displaying the total amount of cards in the deck
	int Deck_length = aDeck.getTotalCards();

	for (int i = 0; i < Deck_length;i++) {           //filling my hand object by drawing the deck
		aDeck.Draw(myHand);
		cout << aDeck.getTotalCards() << endl;
	}

	cout << "\nThe deck is now empty" << endl;      //the Deck should now be empty
	
	cout <<"\nmyHand contains "<<myHand.getInfantry()<<" Infantry cards" << endl;        //testing my getters and setters
	cout << "myHand contains " << myHand.getArtillery() << " Artillery cards" << endl;
	cout << "myHand contains " << myHand.getCavalery() << " Cavalery cards\n" << endl;
	cout << "\nNow proceeding to exchange some Cards-------------------------------" << endl;

	myHand.exchange();   //exchanging my cards for armies
	myHand.exchange();
	myHand.exchange();
	myHand.exchange();
	myHand.exchange();
	
	cout <<"\nmyHand now contains "<< myHand.getInfantry()<<" Infantry cards" << endl;     //again, testing getters and setters
	cout << "myHand now contains " << myHand.getArtillery() << " Artillery cards" << endl; //to see if the exchange worked correctly
	cout << "myHand now contains " << myHand.getCavalery() << " Cavalery cards \n" << endl;
	cout <<"\nmyHand now contains "<< myHand.getArmies()<<" armies" << endl;

	
	cin.get();
	cin.get();
	return 0;
}