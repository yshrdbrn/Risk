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
	return this->artillery;
}

int Hand::getCavalery() {
	return this->cavalery;
}

int Hand::getInfantry() {
	return this->infantry;
}

int Hand::getTotalCards() {
	return this->totalCards;
}

int Hand::getArmies() {
	return this->armies;
}
//-------------------------------------------------------Mutators
void Hand::setArtillery(int Artillery) {
	this->artillery = Artillery;
}

void Hand::setCavalery(int Cavalery) {
	this->cavalery = Cavalery;
}

void Hand::setInfantry(int Infantry) {
	this->infantry = Infantry;
}

void Hand::setTotalCards(int totalCards) {
	this->totalCards = totalCards;
}

void Hand::setArmies(int armies) {
    this->armies = armies;
}

//----------------------------------------------------Increment methods
void Hand::ArtilleryIncrement(int increment) {
	this->artillery += increment;
}

void Hand::InfantryIncrement(int increment) {
	this->infantry += increment;
}

void Hand::CavaleryIncrement(int increment) {
	this->cavalery += increment;
}

void Hand::totalCardsIncrement(int totalCards) {
	this->totalCards += totalCards;
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
			if (this->infantry >= 3) {                      //if there is at least 3 infantries in the deck
				this->infantry -= 3;
				this->exchangeCounter += 5;
				numOfArmies += this->exchangeCounter;
				
				
			}
			else
				cout << "You do not have enough cards to proceed to the exchange" << endl;
		}
		else
			if (type == "artillery" || type == "Artillery") {    //if the type is artillery
				if (this->artillery >= 3) {                       //if there is at least 3 artillery in the deck
					this->artillery -= 3;
					this->exchangeCounter += 5;
					numOfArmies += this->exchangeCounter;
					
					
				}
				else
					cout << "You do not have enough cards to proceed to the exchange" << endl;
			}
			else
				if (type == "cavalery" || type == "Cavalery") {     //if type is cavalery
					if (this->cavalery >= 3) {                      //if there is at least 3 cavalery in the deck
						this->cavalery -= 3;
						this->exchangeCounter += 5;
						this->armies += this->exchangeCounter;
						
						
					}
					else
						cout << "You do not have enough Cards to proceed to the exchange" << endl;
				}
	}

	else {
		cout << "\nproceeding to exchange one card of each type" << endl;  //if the answer to the initial question was "no"
		if (this->infantry>=1 &&this->artillery>=1 &&this->cavalery>=1) {
			this->infantry--;
			this->artillery--;
			this->cavalery--;
			this->exchangeCounter += 5;
			numOfArmies+= this->exchangeCounter;
			
			
			
		}
		
		else {
			cout << "You do not have one card of each type, cannot proceed to the exchange" << endl;
		}
		
	}
}