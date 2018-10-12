#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include "../Part1/country.h"
#include "../part_5/Hand.h"
#include "Dice.h"

class Player{
    private:

     
        std::vector<Country*> countries;
        Hand hand;
        Dice dice;

    public:
        Player();
        Hand getHand();
        void setHand(Hand hand);

       /* Dice getDice();
        void setDice(Dice d);*/

        void setCountries(std::vector<Country*> c);

        std::vector<Country *> getCountries();

        void reinforce();
        void attack();
        void fortify();

};

#endif