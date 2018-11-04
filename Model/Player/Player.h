#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include "../Map/country.h"
#include "../Map/continent.h"
#include "../Cards/Hand.h"
#include "../Dice/Dice_Roll.h"

class Player{
public:

     
        std::vector<country_ptr> countries;
        Hand hand;
        Dice dice;
		string name;

    public:
        Player();
        Hand getHand();
        void setHand(Hand hand);

       Dice getDice();
        void setDice(Dice d);

        void setCountries(std::vector<country_ptr> c);
		void addCountries(country_ptr object);
		void countryNames();
		void setArmies(int armies);
		int getArmies();
		void removeArmies(int armies);

        std::vector<country_ptr> getCountries();

        void reinforce();
        void attack();
        void fortify();

		string getName();
		void  setName(string name);

		

};

#endif