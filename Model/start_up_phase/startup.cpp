#include <iostream>
#include <string>
#include <vector>
#include "random"
#include "startup.h"
#include "../Player/Player.h"
#include "../Map/country.h"
#include "../Map/continent.h"
#include "../Cards/Hand.h"
#include "../Dice/Dice_Roll.h"



using namespace std;
//------------------------------------------------------------------------------------------------------
vector<Player> startup::order_play(vector <Player*> array) {
	
	vector <Player> newArray(array.size());
	
	if (array.size() == 2) {
		std::random_device rd;     // only used once to initialise (seed) engine
		std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
		std::uniform_int_distribution<int> uni(0, 1); // guaranteed unbiased

		auto random_integer = uni(rng);

		if (random_integer == 0) {
			newArray[0] = array[0];
			newArray[1] = array[1];
			return newArray;
		}

		else
		{
			newArray[0] = array[1];
			newArray[1] = array[0];
			return newArray;
		}
	}

	else
       if (array.size() == 3) {
		std::random_device rd;     // only used once to initialise (seed) engine
		std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
		std::uniform_int_distribution<int> uni(0, 2); // guaranteed unbiased


		auto random_integer = uni(rng);

		newArray[0] = array[random_integer];

		auto random2 = uni(rng);
		while (random2 == random_integer) {
			random2 = uni(rng);
		}

		newArray[1] = array[random2];

		auto random3 = uni(rng);
		while (random3 == random2 || random3 == random_integer) {
			random3 = uni(rng);
		}

		newArray[2] = array[random3];

		return newArray;
	}

	else
		if (array.size() == 4) {

			std::random_device rd;     // only used once to initialise (seed) engine
			std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
			std::uniform_int_distribution<int> uni(0, 3); // guaranteed unbiased

			auto random_integer = uni(rng);

			newArray[0] = array[random_integer];

			auto random2 = uni(rng);
			while (random2 == random_integer) {
				random2 = uni(rng);
			}

			newArray[1] = array[random2];

			auto random3 = uni(rng);
			while (random3 == random_integer || random3 == random2) {
				random3 = uni(rng);
			}

			newArray[2] = array[random3];

			auto random4 = uni(rng);
			while (random4 == random_integer || random4 == random2 || random4 == random3) {
				random4 = uni(rng);
			}

			newArray[3] = array[random4];

			return newArray;

		}
		else
			if (array.size() == 5) {
				
				std::random_device rd;     // only used once to initialise (seed) engine
				std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
				std::uniform_int_distribution<int> uni(0, 4); // guaranteed unbiased

				auto random_integer = uni(rng);

				newArray[0] = array[random_integer];

				auto random2 = uni(rng);
				while (random2 == random_integer) {
					random2 = uni(rng);
				}

				newArray[1] = array[random2];

				auto random3 = uni(rng);
				while (random3 == random_integer || random3 == random2) {
					random3 = uni(rng);
				}

				newArray[2] = array[random3];

				auto random4 = uni(rng);
				while (random4 == random_integer || random4 == random2 || random4 == random3) {
					random4 = uni(rng);
				}

				newArray[3] = array[random4];

				auto random5 = uni(rng);
				while (random5 == random_integer || random5 == random2 || random5 == random3 || random5 == random4) {
					random5 = uni(rng);
				}

				newArray[4] = array[random5];

				return newArray;

			}

			else
				if (array.size() == 6) {

					std::random_device rd;     // only used once to initialise (seed) engine
					std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
					std::uniform_int_distribution<int> uni(0, 5); // guaranteed unbiased

					auto random_integer = uni(rng);

					newArray[0] = array[random_integer];

					auto random2 = uni(rng);
					while (random2 == random_integer) {
						random2 = uni(rng);
					}

					newArray[1] = array[random2];

					auto random3 = uni(rng);
					while (random3 == random_integer || random3 == random2) {
						random3 = uni(rng);
					}

					newArray[2] = array[random3];

					auto random4 = uni(rng);
					while (random4 == random_integer || random4 == random2 || random4 == random3) {
						random4 = uni(rng);
					}

					newArray[3] = array[random4];

					auto random5 = uni(rng);
					while (random5 == random_integer || random5 == random2 || random5 == random3 || random5 == random4) {
						random5 = uni(rng);
					}

					newArray[4] = array[random5];

					auto random6 = uni(rng);
					while (random6 == random_integer || random6 == random2 || random6 == random3 || random6 == random4 || random6 == random5) {
						random6 = uni(rng);
					}

					newArray[5] = array[random6];

					return newArray;
				}

			}


			static void distributing_countries(vector <country_ptr> array, vector<Player *> ordered_turns) {
				for (int i = 0; i < array.size();i++) {
					
					int a = 0;
					
					ordered_turns[a]->addCountries(array[i]);
					if (a == ordered_turns.size()) {
						a = 0;
					} 
					
					a++;
				}
			}

			static void distributing_armies(vector<Player> ordered_turns) {

			}







