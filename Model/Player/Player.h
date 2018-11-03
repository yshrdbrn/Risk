#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include "../Map/country.h"
#include "../Cards/Hand.h"
#include "../Dice/Dice_Roll.h"

class Player{
    private:

     
        std::vector<Country*> countries;
        Hand hand;
        Dice dice;
        int id;

    public:
        Player();
        Player(int playerId);
        Hand getHand();
        void setHand(Hand hand);

       Dice getDice();
        void setDice(Dice d);

        void setCountries(std::vector<Country*> c);

        std::vector<Country *> getCountries();

        void reinforce();
        void attack();
        void fortify();

        int getId() const;
        void setId(int id);

};

#endif