#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "../Player/Player.h"


using namespace std;




class startup {
public:
	static vector<Player*> order_play(vector <Player*> array);
	static void distributing_countries(vector <country_ptr> array, vector<Player*> ordered_turns);
	static void distributing_armies(vector<Player*> ordered_turns);
	static void placing_armies(vector<Player*> ordered_turns);
	
};