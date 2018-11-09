/*
Bilal Rana 40013408
COMP 345 Assignment 1: Part 3 (Dice Roll)
Team Members: Mehdi, Youssef, Yashar. 
*/

#include <iostream>
#include <random>
#include <ctime>
#include "Dice_Roll.h"

using namespace std;

// Creating a default Dice constructor
Dice::Dice() {
	//Storing the number of times each value was recorded after roll.
	distributionDiceRoll[0] = 0;
	distributionDiceRoll[1] = 0;
	distributionDiceRoll[2] = 0;
	distributionDiceRoll[3] = 0;
	distributionDiceRoll[4] = 0;
	distributionDiceRoll[5] = 0;
	diceRollTotal = 0;
}
//Destructor
Dice::~Dice(){
}

void  Dice::diceRoll( int numberOfDice){
	//Used in method to return value of the dice in order
	int diceValue;

	/* Loop which rolls number of dices based on user input
	diceValue uses the method singleRoll() in order to 
	randomly compute a value between 1-6 for each dice roll.
	*/
	for (int i = 0; i < numberOfDice; i++) {
		diceValue = valueOfDice();
		cout << "The number rolled for dice number " << i + 1 << " is " << diceValue << endl;
	}
}
	//Method which returns value of Dice to use in the diceRoll method above. 
int Dice::valueOfDice()
{
	int diceValue = (int)((6 * rand() / (RAND_MAX + 1.0)) + 1);
	distributionDiceRoll[diceValue - 1] += 1;
	diceRollTotal++;
	return diceValue;
}
	//Method which calculates the percentage of all individual values up rolled up to now.
void Dice::distributionStatistics(){

	for (int i = 0; i <= 5; i++) {
		double percentageOfEachValue = ((double)distributionDiceRoll[i] / diceRollTotal) * 100;
		cout << "The number " << i + 1 << " was rolled " << percentageOfEachValue << "% of the time." << endl;
		
	};
}

