#include <iostream>
#include "Hand.h"
#include "Deck.h"
#include <string>

using namespace std;
//------------------------------------------------Constructors
Hand::Hand() {

}

Hand::Hand(int artillery , int cavalery , int infantry) : cavalery(cavalery) , artillery(artillery) , infantry(infantry){}
//--------------------------------------------------------Getters
int Hand::getArtillery() {
	return artillery;
}

int Hand::getCavalery() {
	return cavalery;
}

int Hand::getInfantry() {
	return infantry;
}

int Hand::getTotalCards() {
	return totalCards;
}

int Hand::getArmies() {
	return armies;
}
//-------------------------------------------------------Mutators
void Hand::setArtillery(int Artillery) {
	artillery = Artillery;
}

void Hand::setCavalery(int Cavalery) {
	cavalery = Cavalery;
}

void Hand::setInfantry(int Infantry) {
	infantry = Infantry;
}

void Hand::setTotalCards(int totalCards) {
	totalCards = totalCards;
}

void Hand::setArmies(int armies) {
	armies = armies;
}

//----------------------------------------------------Increment methods
void Hand::ArtilleryIncrement(int increment) {
	artillery += increment;
}

void Hand::InfantryIncrement(int increment) {
	infantry += increment;
}

void Hand::CavaleryIncrement(int increment) {
	cavalery += increment;
}

void Hand::totalCardsIncrement(int totalCards) {
	totalCards += totalCards;
}
//-------------------------------------------------------exchange_method
void Hand::exchange(int& numOfArmies) {
	bool checker = false;
	string type;
	string yes;

	cout << "Do you wish to exchange 3 cards of the same type?(yes/no):";
	cin >> yes;

	if ((yes == "yes" || yes == "Yes") == false && (yes == "no" || yes == "No") == false) {      //looks if the user entered a valid (yes/no)
		while (checker == false) {
			cout << "you did not enter yes/no, please try again:";
			cin >> yes;
			if ((yes == "yes" || yes == "Yes") == true || (yes == "no" || yes == "No") == true){
				checker = true;
			}
		}
	}
	checker = false;

	if (yes == "yes" || yes == "Yes") {                                 //if the answer is yes, proceeds to ask which type it is
		cout << "Please enter the type of the cards you wish to exchange" << endl;
		cin >> type;
		if ((type == "infantry" || type == "Infantry" || type == "artillery" || type == "Artillery" ||
			 type == "cavalery" || type == "Cavalery") == checker) {           //if the type is not one of these, please re enter
			while (checker == false)
			{
				cout << "Invalid type:: Please re enter the type you would like to exchange" << endl;
				cin >> type;
				if ((type == "infantry" || type == "Infantry" || type == "artillery" || type == "Artillery" ||
					 type == "cavalery" || type == "Cavalery") == true) {
					checker = true;
				}

			}
		}

		if (type == "infantry" || type == "Infantry") {       //if the type is infantry
			if (infantry >= 3) {                      //if there is at least 3 infantries in the deck
				infantry -= 3;
				exchangeCounter += 5;
				numOfArmies += exchangeCounter;


			}
			else
				cout << "You do not have enough cards to proceed to the exchange" << endl;
		}
		else
		if (type == "artillery" || type == "Artillery") {    //if the type is artillery
			if (artillery >= 3) {                       //if there is at least 3 artillery in the deck
				artillery -= 3;
				exchangeCounter += 5;
				numOfArmies += exchangeCounter;


			}
			else
				cout << "You do not have enough cards to proceed to the exchange" << endl;
		}
		else
		if (type == "cavalery" || type == "Cavalery") {     //if type is cavalery
			if (cavalery >= 3) {                      //if there is at least 3 cavalery in the deck
				cavalery -= 3;
				exchangeCounter += 5;
				armies += exchangeCounter;


			}
			else
				cout << "You do not have enough Cards to proceed to the exchange" << endl;
		}
	}

	else {
		cout << "\nproceeding to exchange one card of each type" << endl;  //if the answer to the initial question was "no"
		if (infantry>=1 &&artillery>=1 &&cavalery>=1) {
			infantry--;
			artillery--;
			cavalery--;
			exchangeCounter += 5;
			numOfArmies+= exchangeCounter;



		}

		else {
			cout << "You do not have one card of each type, cannot proceed to the exchange" << endl;
		}

	}
}