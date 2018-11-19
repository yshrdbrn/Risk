#include <iostream>
#include <string>
#include <vector>
#include "random"
#include "startup.h"
#include "../../Model/Player/Player.h"
#include "../../Model/Map/country.h"
#include "../../Model/Map/continent.h"
#include "../../Model/Cards/Hand.h"
#include "../../Model/Dice/Dice_Roll.h"
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
        array[i]->setOwner(ordered_turns[a]);
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
void startup:: placing_armies(vector<Player*> ordered_turns) {//Placing Armies method, prompts users to place their armies

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
    else // ordered_turns.size() == 6
        totalArmies = 20;


    for (int i = 0;i < totalArmies;i++) {  //the loop keeps going as long total armies is not 0
        for (int a = 0; a < ordered_turns.size(); a++) {
            auto countries = ordered_turns[a]->getCountries();
            int index = ordered_turns[a]->whichCountryToPlaceOneArmyOn();
            countries[index]->incrementArmies(1); //increments the army on the country selected by 1
            ordered_turns[a]->removeArmies(1); // Remove one pending army to be placed from player
        }
    }
}







