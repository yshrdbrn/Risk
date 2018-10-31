#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include "../Map/country.h"
#include "../Map/continent.h"
#include "../Cards/Hand.h"
#include "../Dice/Dice_Roll.h"

class Player{
    private:

        std::vector<Continent*> continents;
        std::vector<Country*> countries;
        Hand hand;
        Dice dice;

    public:
        Player();

        Hand getHand();
        void setHand(Hand&);

        Dice getDice();
        void setDice(Dice d);

        void setCountries(std::vector<Country*>& );
        std::vector<Country *> getCountries();

        void setContinents(std::vector<Continent*>&);
        std::vector<Continent*> getContinents();

        void reinforce();
        void attack();
        void fortify();

};

#endif