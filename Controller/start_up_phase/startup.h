#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "../../Model/Player/Player.h"


using namespace std;

// all the methods in this class are static
class startup { 
public:
	static vector<Player*> order_play(vector <Player*> array);       // determining the order of play
	static void distributing_countries(vector <country_ptr> array, vector<Player*> ordered_turns); //distibuting the countries to the players
	static void distributing_armies(vector<Player*> ordered_turns); //distributing the armies to the players
	static void placing_armies(vector<Player*> ordered_turns);     //prompting the players to place armies on their countries
	
};