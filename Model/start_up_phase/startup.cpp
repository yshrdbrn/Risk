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

vector<Player*> startup::order_play(vector <Player*> array) {              //method that takes in a vector of players
	unsigned seed = chrono::system_clock::now().time_since_epoch().count(); //and returns another vector of players with randomized positions

	shuffle(array.begin(), array.end(), std::default_random_engine(seed));

	return array;
	    
}
//---------------------------------------------------------------------------------------------------------

void startup::distributing_countries(vector <country_ptr> array, vector<Player *> ordered_turns) { // method that distributes countries to players
				
				unsigned seed = chrono::system_clock::now().time_since_epoch().count();  //setting the seed to system clock

				shuffle(array.begin(), array.end(), std::default_random_engine(seed));  //calling the shuffle method to randomize the 
				                                                                        //country array
				int a = 0;
				for (int i = 0; i < array.size();i++) {                        //distributing the countries to the players
					ordered_turns[a]->addCountries(array[i]);                  //and setting the country's player to that player.
					array[i]->setPlayer(ordered_turns[a]);
					a++;
					if (a == ordered_turns.size()) {
						a = 0;
					} 
				}

				
			}
//---------------------------------------------------------------------------------------------------------
			
 void startup::distributing_armies(vector<Player*> ordered_turns) {   //Distributing Armies method, looks at the numbe rof players
				                                                      //in the Vector of players, and distributes an amount of armies
				if (ordered_turns.size() == 2) {                      //for all of them based on that
					for (int i = 0;i < ordered_turns.size();i++) {
						
						ordered_turns[i]->setArmies(40);            //if two players, each gets 40 armies
					}
				}
				
				else if (ordered_turns.size() == 3) {
					for (int i = 0;i < ordered_turns.size();i++) { //if 3 players, each gets 35 armies
						
						ordered_turns[i]->setArmies(35);
					}
				}
				
				else if (ordered_turns.size() == 4) {
					for (int i = 0;i < ordered_turns.size();i++) {  // if 4 players, each gets 30 armies
						
						ordered_turns[i]->setArmies(30);
					}
				}
				
				else if (ordered_turns.size() == 5) {
					for (int i = 0;i < ordered_turns.size();i++) {  //if 5 players, each gets 25 armies
						
						ordered_turns[i]->setArmies(25);
					}
				}
				
				else if (ordered_turns.size() == 6) {
					for (int i = 0;i < ordered_turns.size();i++) {  //if 6 players, each gets 20 armies
						
						ordered_turns[i]->setArmies(20);
					}
				}
			}
 //-----------------------------------------------------------------------------------------------------------------
 void startup:: placing_armies(vector<Player*> ordered_turns) {  //Placing Armies method, prompts users to place their armies
	 int totalArmies;                                            //on their countries
	 int country;
	 
	 if (ordered_turns.size()==2)              //the variable totalArmies if used as a delimiter for the for loop below
		 totalArmies = 40;
	 else if (ordered_turns.size() == 3)
		 totalArmies = 35;
	 else if (ordered_turns.size() == 4)
		 totalArmies = 30;
	 else if (ordered_turns.size() == 5)
		 totalArmies = 25;
	 else if (ordered_turns.size() == 6)
		 totalArmies = 20;


	 
	 for (int i = 0;i < totalArmies;i++) {  //the loop keeps going as long total armies is not 0
		 cout << endl;
		 
		 for (int a = 0;a < ordered_turns.size();a++) {
			 if (ordered_turns[a]->getCountries().size() == 0)
				 cout << ordered_turns[a]->getName() << " you have no countries" << endl;  //If a player has no armies, he is skipped over
			 else {

				 cout << ordered_turns[a]->getName()<<", you have "<<ordered_turns[a]->getArmies()<<" armies and" <<
					 " your countries are : " << endl;           //informs the user of the amount of armies they have left and the countries
				                                                 //they own.
				 for (int c = 0;c < ordered_turns[a]->getCountries().size();c++) {
					 cout << c << " " << ordered_turns[a]->getCountries()[c]->getName() << " : " <<
						 ordered_turns[a]->getCountries()[c]->getArmies() << " armies" << endl;
				 }

				 cout << "\nPlease enter the number of the country you would like to place an army on : ";
				 cin >> country;                                  //prompts the user to select one of his countries to place an army on

				 while (country > ordered_turns[a]->getCountries().size() - 1 || country < 0) {
					 cout << "Invalid input, please try again: ";  //If the user enters non valid input (a country he does not own),
					 cin >> country;                               // error message is displayed until he enters a valid country
				 }
				 cout << endl;

				 ordered_turns[a]->getCountries()[country]->incrementArmies(1); //increments the army on the country selected by 1
				 ordered_turns[a]->removeArmies(1);                             //removes 1 army from the player

			 } 


		 }
	 }
 }







