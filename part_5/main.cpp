#include <iostream>
#include "Deck.h"
#include "Hand.h"
#include "random"

using namespace std;

int main() {
	Deck aDeck(43);
	Hand myHand;
	
	cout << aDeck.getTotalCards() << endl;
	int Deck_length = aDeck.getTotalCards();

	for (int i = 0; i < Deck_length;i++) {
		aDeck.Draw(myHand);
		cout << aDeck.getTotalCards() << endl;
	}
	

	cout << myHand.getArmies() << endl;

	myHand.exchange("infantry");
	cout << myHand.getInfantry() << endl;
	cout << myHand.getArmies() << endl;

	
	cin.get();
	return 0;
}