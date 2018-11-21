#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include "../Map/country.h"
#include "../Cards/Hand.h"
#include "../Dice/Dice_Roll.h"
#include "Strategy.h"

typedef std::shared_ptr<Country> country_ptr;

class State;

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

    virtual ~Player();

    Player(int playerId, Strategy *strategy1);
        Hand *getHand();
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
        void addCountry(country_ptr countryPtr);
        void removeCountry(country_ptr countryPtr);

        void reinforce(State *);
        void attack(State *);
        void fortify(State *);

        /**
         * This method will return the index of which country to place one army on
         * @return
         */
        int whichCountryToPlaceOneArmyOn();


		string getName();
		void  setName(string name);


        int getId() const;
        void setId(int id);


};

#endif