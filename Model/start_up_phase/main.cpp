#include "startup.h"
#include <iostream>
#include <string>
#include "../Player/Player.h"
#include <vector>



using namespace std;

int main() {
	int numberPlayers = 4;
	vector <Player*> initial_array;
	vector<Player*> order_array;
	vector<country_ptr> countries;

	Country* a = new Country("usa");

	countries.push_back(&a);
	
	Player p1;
	Player p2;
	Player p3;
	Player p4;
	string name;

	initial_array.push_back(&p1);
	initial_array.push_back(&p2);
	initial_array.push_back(&p3);
	initial_array.push_back(&p4);

	

	cout << "Please enter the names of every player" << endl;

	for (int i = 0; i<numberPlayers; i++) {
		cin >> name;
		initial_array[i]->setName(name);
	}

	order_array=startup::order_play(initial_array);
	int initialSize = order_array.size();

	cout << "The order of play of the players is the following: " << endl;
	for (int i = 0; i<numberPlayers; i++) {
		cout << order_array[i]->getName() << endl;
	}

	cout << "now distributing countries" << endl;
	startup::distributing_countries(countries, order_array);
	

	

	cin.get();
	cin.get();
	return 0;
}