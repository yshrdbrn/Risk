#pragma once

/* Defining variables and functions which will be used
*/

class Dice {
public: 
	Dice();
	~Dice();
	
	int valueOfDice();
	void distributionStatistics();
	void diceRoll(int numberOfDice);
	
private: 
	int diceRollTotal;
	int distributionDiceRoll[6];

};