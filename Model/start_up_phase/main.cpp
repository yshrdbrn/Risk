#include "startup.h"
#include <iostream>
#include <string>
#include "../Player/Player.h"
#include <vector>
#include "../Maploader/mapLoader.h"
#include <random>
#include <algorithm>
#include <chrono>



using namespace std;

int main() {
	int numberPlayers = 4;
	vector <Player*> initial_array;
	vector<Player*> order_array;
	vector<country_ptr> countries;

	country_ptr a = std::make_shared<Country>("usa");
	country_ptr b = std::make_shared<Country>("france");
	country_ptr c = std::make_shared<Country>("China");
	country_ptr d = std::make_shared<Country>("Japan");
	country_ptr e = std::make_shared<Country>("Indonesia");

	countries.push_back(a);
	countries.push_back(b);
	countries.push_back(c);
	countries.push_back(d);
	countries.push_back(e);
	
	Player p1;
	Player p2;
	Player p3;
	Player p4;
	string name;

	Hand Hand1;
	Hand Hand2;
	Hand Hand3;
	Hand hand4;

	initial_array.push_back(&p1);
	initial_array.push_back(&p2);
	initial_array.push_back(&p3);
	initial_array.push_back(&p4);

	

	cout << "Please enter the names of every player:\n" << endl;

	for (int i = 0; i<initial_array.size(); i++) {
		cin >> name;
		initial_array[i]->setName(name);
	}

	order_array=startup::order_play(initial_array);
	int initialSize = order_array.size();

	cout << " \nThe order of play of the players is the following: \n " << endl;
	for (int i = 0; i<numberPlayers; i++) {
		cout << order_array[i]->getName() << endl;
	}

	//------------------------------------------------------------------------------
	cout << " \nnow distributing the countries to the Players\n" << endl;
	startup::distributing_countries(countries, order_array);


	for (int i = 0; i < order_array.size();i++) {
		order_array[i]->countryNames();
	}
	//--------------------------------------------------------------------------------
	cout << "\nNow distributing armies to the players" << endl;
	
	
	startup::distributing_armies(order_array);

	for (int i = 0;i < order_array.size();i++) {
		cout << order_array[i]->getName()<< " has " << order_array[i]->getHand().getArmies() << " armies\n"<< endl;
	}

	startup::placing_armies(order_array);

	


	

	std::cin.get();
	std::cin.get();
	

	

	cin.get();
	cin.get();
	return 0;
}