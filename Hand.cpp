#include <iostream>
#include "Hand.h"
#include "Deck.h"
#include <string>

using namespace std;
//------------------------------------------------Constructors
Hand::Hand() {

}
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
void Hand::exchange(string type) {
	bool checker = false;
	if ((type == "infantry" || type == "Infantry" || type == "artillery" || type == "Artillery" ||
		type == "cavalery" || type == "Cavalery") == checker) {
		while (checker==false)
		{
			cout << "Invalid type:: Please re enter the type you would like to exchange" << endl;
			cin >> type;
			if ((type == "infantry" || type == "Infantry" || type == "artillery" || type == "Artillery" ||
				type == "cavalery" || type == "Cavalery") == true) {
				checker = true;
			}

}
	}
	
	if (type=="infantry"|| type=="Infantry") {
		if (this->infantry >= 3) {
			this->infantry -= 3;
			this->exchangeCounter += 5;
			this->armies += this->exchangeCounter;
		}
		else
			cout << "You do not have enough cards to proceed to the exchange" << endl;
	}
	else
		if (type == "artillery" || type == "Artillery") {
			if (this->artillery >= 3) {
				this->artillery -= 3;
				this->exchangeCounter += 5;
				this->armies += this->exchangeCounter;
			}
			else
				cout << "You do not have enough cards to proceed to the exchange" << endl;
		}
		else
			if (type == "cavalery" || type == "Cavalery") {
				if (this->cavalery >= 3) {
					this->cavalery -= 3;
					this->exchangeCounter += 5;
					this->armies += this->exchangeCounter;
				}
				else
					cout<<"You do not have enough Cards to proceed to the exchange"<<endl;
			}
}