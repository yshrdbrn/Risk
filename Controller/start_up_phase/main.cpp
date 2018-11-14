#include "startup.h"
#include <iostream>
#include <string>
#include "../../Model/Player/Player.h"
#include <vector>
#include "../../Model/Maploader/mapLoader.h"
#include <random>
#include <algorithm>
#include <chrono>



using namespace std;

int main() {
	
	vector <Player*> initial_array;  //Vector which holds the players at first
	vector<Player*> order_array;     //vector which holds the players after randomized order
	vector<country_ptr> countries;   //vector of countries

	country_ptr a = std::make_shared<Country>("usa");        //creating countries
	country_ptr b = std::make_shared<Country>("france");
	country_ptr c = std::make_shared<Country>("China");
	country_ptr d = std::make_shared<Country>("Australia");
	country_ptr e = std::make_shared<Country>("Japan");

	
	 
	countries.push_back(a);              //pushing the countries to a vector of countries
	countries.push_back(b);
	countries.push_back(c);
	countries.push_back(d);
	countries.push_back(e);
	
	 
	Player p1;                     
	Player p2;
	Player p3;
	Player p4;
	Player p5;
	string name;

	initial_array.push_back(&p1);  //pushing the players in a vector of Players
	initial_array.push_back(&p2);
	initial_array.push_back(&p3);
	initial_array.push_back(&p4);
	initial_array.push_back(&p5);

	

	cout << "Please enter the names of every player:\n" << endl;     

	for (int i = 0; i<initial_array.size(); i++) {
		cin >> name;
		initial_array[i]->setName(name);              //Setting the name of each Players based on the input given
	}

	order_array=startup::order_play(initial_array);
	int initialSize = order_array.size();

	cout << " \nThe order of play of the players is the following: \n " << endl;
	for (int i = 0; i<order_array.size(); i++) {           // Randomizing the order of play of each player
		cout << order_array[i]->getName() << endl;
	}

	//------------------------------------------------------------------------------
	cout << endl;
	cout << " \nnow distributing the countries to the Players" << endl;     //distributing countries to the players
	startup::distributing_countries(countries, order_array);


	for (int i = 0; i < order_array.size();i++) {
		order_array[i]->countryNames();
	}
	//--------------------------------------------------------------------------------
	cout << endl;
	cout << "\nNow distributing armies to the players\n" << endl;         //distributing armies to the players
	
	startup::distributing_armies(order_array);

	for (int i = 0;i < order_array.size();i++) {
		cout << order_array[i]->getName()<< " has " << order_array[i]->getHand().getArmies() << " armies\n"<< endl;
	}  //prints how much armies each player has

	startup::placing_armies(order_array);   // prompts the users to place their armies on their countries

	


	

	std::cin.get();
	std::cin.get();
	

	

	cin.get();
	cin.get();
	return 0;
}