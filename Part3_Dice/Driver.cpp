#include <iostream>;
#include <random>;
#include "Dice_Roll.h";

using namespace std;

int main() {
	int numberOfDice;

	cout << "Please enter the number of Dice you want to roll between 1 and 3: " << endl;

	cin >> numberOfDice;

	Dice dice;
	dice.diceRoll(numberOfDice);
	dice.distributionStatistics();

	

	cin.get();
	cin.get();

	return 0;
	


}