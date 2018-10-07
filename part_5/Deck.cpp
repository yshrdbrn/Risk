#include <iostream>
#include "Deck.h"
#include "random"
#include "Hand.h"

using namespace std;
//--------------------------------------------------Constructors
Deck::Deck() {};

Deck::Deck(int totalCards) {
	if (totalCards % 3 == 0) {
		 artillery=(totalCards / 3);
		 cavalery=(totalCards / 3);
		 infantry=(totalCards / 3);
	}
	else
		if (totalCards % 3 == 1) {
			int storage = (totalCards - 1);
			artillery=(storage / 3);
			cavalery=(storage / 3);
			infantry=(storage / 3);

			std::random_device rd;     // only used once to initialise (seed) engine
			std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
			std::uniform_int_distribution<int> uni(1, 3); // guaranteed unbiased

			auto random_integer = uni(rng);

			if (random_integer == 1) {        //---->if the random integer is 1, then the additional 1 goes to Artillery
				artillery++;  //---->if it is 2, then the additional 1 goes to Cavalery
			}                                 //---->if it is 3, then the additional 1 goes to Infantry

			else
				if (random_integer == 2) {
					cavalery++;
				}
				else
					if (random_integer == 3) {
						infantry++;
					}

		}
		else
			if (totalCards % 3 == 2) {
				int storage = (totalCards - 2);
				artillery=(storage / 3);
				cavalery=(storage / 3);
				infantry=(storage / 3);

				std::random_device rd;     // only used once to initialise (seed) engine
				std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
				std::uniform_int_distribution<int> uni(1, 3); // guaranteed unbiased

				auto random_integer = uni(rng);

				if (random_integer == 1) {        //Here, we randomly choose a number, if that number is 1, then Artillery
					cavalery++;         //remains at (storage/3) and we add 1 to both cavalery and Infantry
					infantry++;         
				}                                 

				else
					if (random_integer == 2) {     //if the number is 2--> Cavalery remains at (storage/3), we add to the two others
						artillery++;
						infantry++;
					}
					else
   						if (random_integer == 3) {  //if number is 3--> infantry remains at (storage/3), we add to the two others.
							artillery++;
							cavalery++;
						}
				

			}
	this->totalCards = totalCards; //-->variable keeping track of how much cards total there is in the deck.
}

//---------------------------------------------------Accessors

int Deck::getArtillery() {
	return this->artillery;
}

int Deck::getCavalery() {
	return this->cavalery;
}

int Deck::getInfantry() {
	return this->infantry;
}

int Deck::getTotalCards() {
	return this->totalCards;
}
//---------------------------------------------------Mutators
void Deck::setArtillery(int Artillery) {
	this->artillery = Artillery;
}

void Deck::setCavalery(int Cavalery) {
	this->cavalery = Cavalery;
}

void Deck::setInfantry(int Infantry) {
	this->infantry = Infantry;
}

void Deck::setTotalCards(int totalCards) {
	this->totalCards = totalCards;
}
//----------------------------------------------------Increment functions
void Deck::ArtilleryIncrement(int increment) {
	this->artillery += increment;
}

void Deck::InfantryIncrement(int increment) {
	this->infantry += increment;
}

void Deck::CavaleryIncrement(int increment) {
	this->cavalery += increment;
}
//--------------------------------------------------------------Draw method

void Deck::Draw(Hand& myHand) {
	if (this->totalCards == 0) {
		cout << "The deck is empty" << endl;
	}
	
	std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	std::uniform_int_distribution<int> uni(1, 3); // guaranteed unbiased

	auto random_integer = uni(rng); 
	
	if (this->totalCards == 0) {
		 cout << "The deck is empty" << endl;
}
	else {
		while ((random_integer == 1 && this->artillery == 0) || (random_integer == 2 && this->cavalery == 0)
			|| (random_integer == 3 && this->infantry == 0))
		{
			if (random_integer == 1 && this->artillery == 0) {
				while (random_integer == 1) {
					random_integer = uni(rng);
				}
			}
			else
				if (random_integer == 2 && this->cavalery == 0) {
					while (random_integer == 2) {
						random_integer = uni(rng);
					}
				}
				else
					if (random_integer == 3 && this->infantry == 0) {
						while (random_integer == 3) {
							random_integer = uni(rng);
						}

					}
		}
		if (random_integer == 1 & this->artillery != 0) {
				this->artillery -= 1;
				this->totalCards -= 1;
				myHand.ArtilleryIncrement(1);
				myHand.totalCardsIncrement(1);
				cout << "Drawing one artillery" << endl;
			}
			else
				if (random_integer == 2 & this->cavalery != 0) {
					this->cavalery -= 1;
					this->totalCards -= 1;
					myHand.CavaleryIncrement(1);
					myHand.totalCardsIncrement(1);
					cout << "Drawing one Cavalery" << endl;
				}
				else
					if (random_integer == 3 & this->infantry != 0) {
						this->infantry -= 1;
						this->totalCards -= 1;
						myHand.InfantryIncrement(1);
						myHand.totalCardsIncrement(1);
						cout << "Drawing one Infantry" << endl;
					}
		}
	}
