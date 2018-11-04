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
#include <chrono>



using namespace std;
//------------------------------------------------------------------------------------------------------

vector<Player*> startup::order_play(vector <Player*> array) {
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();

	shuffle(array.begin(), array.end(), std::default_random_engine(seed));

	return array;
	    
}

void startup::distributing_countries(vector <country_ptr> array, vector<Player *> ordered_turns) {
				
				unsigned seed = chrono::system_clock::now().time_since_epoch().count();

				shuffle(array.begin(), array.end(), std::default_random_engine(seed));
				
				int a = 0;
				for (int i = 0; i < array.size();i++) {
					ordered_turns[a]->addCountries(array[i]);
					a++;
					if (a == ordered_turns.size()) {
						a = 0;
					} 
				}
			}

			
 void startup::distributing_armies(vector<Player*> ordered_turns) {
				
				if (ordered_turns.size() == 2) {
					for (int i = 0;i < ordered_turns.size();i++) {
						
						ordered_turns[i]->setArmies(40);
					}
				}
				
				else if (ordered_turns.size() == 3) {
					for (int i = 0;i < ordered_turns.size();i++) {
						
						ordered_turns[i]->setArmies(35);
					}
				}
				
				else if (ordered_turns.size() == 4) {
					for (int i = 0;i < ordered_turns.size();i++) {
						
						ordered_turns[i]->setArmies(30);
					}
				}
				
				else if (ordered_turns.size() == 5) {
					for (int i = 0;i < ordered_turns.size();i++) {
						
						ordered_turns[i]->setArmies(25);
					}
				}
				
				else if (ordered_turns.size() == 6) {
					for (int i = 0;i < ordered_turns.size();i++) {
						
						ordered_turns[i]->setArmies(20);
					}
				}
			}

 void startup:: placing_armies(vector<Player*> ordered_turns) {
	 int totalArmies;
	 int country;
	 
	 if (ordered_turns.size()==2)
		 totalArmies = 40;
	 else if (ordered_turns.size() == 3)
		 totalArmies = 35;
	 else if (ordered_turns.size() == 4)
		 totalArmies = 30;
	 else if (ordered_turns.size() == 5)
		 totalArmies = 25;
	 else if (ordered_turns.size() == 6)
		 totalArmies = 20;


	 
	 for (int i = 0;i < totalArmies;i++) {
		 cout << endl;
		 
		 for (int a = 0;a < ordered_turns.size();a++) {
			 cout << ordered_turns[a]->getName() << " your countries are : " << endl;
			 
			 for (int c = 0;c < ordered_turns[a]->getCountries().size();c++) {
				 cout << c <<" "<< ordered_turns[a]->getCountries()[c]->getName()<<" : "<<
					 ordered_turns[a]->getCountries()[c]->getArmies() <<" armies"<< endl;
			 }
			 
			 cout << "\nPlease enter the number of the country you would like to place an army on : " << endl;
			 cin >> country;

			 ordered_turns[a]->getCountries()[country]->incrementArmies(1);
			 


			 


		 }
	 }
 }







