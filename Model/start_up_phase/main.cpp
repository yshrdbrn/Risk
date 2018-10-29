#include "startup.h"
#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

int main() {
	string player1;
	string player2;
	string player3;
	string player4;
	string player5;
	string player6;

	cout << "Please enter the names of each Player, one by one:" << endl;
	cin >> player1 >> player2 >> player3 >> player4 >> player5 >> player6 >> endl;

	cout << startup::order_play(player1, player2, player3, player4, player5, player6) << endl;
	cin.get();
	return 0;
}