#pragma once

/* Defining variables and functions which will be used
*/
#include <iostream>
#include <vector>

class Dice {
public: 
	Dice();
	~Dice();
	
	int valueOfDice();
	void distributionStatistics();
	std::vector<int>& diceRoll(int numberOfDice);
	
private: 
	int diceRollTotal;
	int distributionDiceRoll[6];

};