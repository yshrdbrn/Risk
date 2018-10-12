#pragma once
#include <iostream>
#include <string>
#include "Hand.h"
#include "common.h"

using namespace std;

class Deck {
public:
	Deck();
	Deck(int totalCards);
	
	int getArtillery();
	int getInfantry();
	int getCavalery();
	int getTotalCards();

	void setArtillery(int Artillery);
	void setInfantry(int Artillery);
	void setCavalery(int Artillery);
	void setTotalCards(int totalCards);
	void ArtilleryIncrement(int increment);
	void InfantryIncrement(int increment);
	void CavaleryIncrement(int increment);

	void Draw(Hand& myHand);

private:
	int artillery = 0;
	int infantry = 0;
	int cavalery = 0;
	int totalCards = 0;
};