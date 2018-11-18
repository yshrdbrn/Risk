#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include "../Map/country.h"
#include "../Cards/Hand.h"
#include "../Dice/Dice_Roll.h"
#include "Strategy.h"
#include "../GameState/Subject.h"
#include "../../View/PhaseView.h"

typedef std::shared_ptr<Country> country_ptr;

class Player : Subject{
    private:

        std::vector<country_ptr> countries;
        Hand * hand;
        Dice * dice;
        string name;
        int id;
        Strategy *strategy;
        std::string message;
        PhaseView * view;

    public:
        Player();
        Player(int playerId, Strategy *strategy1 ,Dice *, Hand* ,PhaseView*);

        

        Hand *getHand();
        void setHand(Hand*);

        Dice * getDice();
        void setDice(Dice *);

        void setCountries(std::vector<country_ptr>& );
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

        void startturn();

        void setMessage(std::string);


        int getId() const;
        void setId(int id);

        void notifyObservers() override;


};

#endif