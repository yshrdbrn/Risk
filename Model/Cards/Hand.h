#pragma once
#include <iostream>
#include <string>

using namespace std;

class Hand {
public:
	Hand();

	int getArtillery();
	int getInfantry();
	int getCavalery();
	int getTotalCards();
	int getArmies();

	void setArtillery(int Artillery);
	void setInfantry(int Artillery);
	void setCavalery(int Artillery);
	void setTotalCards(int totalCards);
	void setArmies(int armies);

	void ArtilleryIncrement(int increment);
	void InfantryIncrement(int increment);
	void CavaleryIncrement(int increment);
	void totalCardsIncrement(int increment);
	
	void exchange();
private:
	int artillery = 0;
	int infantry = 0;
	int cavalery = 0;
	int totalCards = 0;
	int armies = 0;
	int exchangeCounter = 0;
};