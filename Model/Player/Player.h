#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include "../Map/country.h"
#include "../Cards/Hand.h"
#include "../Dice/Dice_Roll.h"
#include "Strategy.h"

typedef std::shared_ptr<Country> country_ptr;

class Player{
    private:

        std::vector<country_ptr> countries;
        Hand hand;
        Dice * dice;
        string name;
        int id;
        Strategy *strategy;

    public:
        Player();
        Player(int playerId, Strategy *strategy1 ,Dice *);
        Hand getHand();
        void setHand(Hand&);

        Dice * getDice();
        void setDice(Dice *);

        void setCountries(std::vector<country_ptr>& );
		void addCountries(country_ptr object);
		void countryNames();
		void setArmies(int armies);
		int getArmies();
		void removeArmies(int armies);

        std::vector<country_ptr> getCountries();

        std::string reinforce();
        std::string attack();
        std::string fortify();

		string getName();
		void  setName(string name);


        int getId() const;
        void setId(int id);


};

#endif