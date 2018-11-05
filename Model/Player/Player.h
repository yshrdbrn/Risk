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
        std::vector<country_ptr> countries;
        Hand hand;
        Dice * dice;
        int id;

    public:
        Player();

        Player(int playerId);
        Hand getHand();
        void setHand(Hand&);

        Dice * getDice();
        void setDice(Dice *);

        void setCountries(std::vector<country_ptr>& );

        std::vector<country_ptr> getCountries();

        void setContinents(std::vector<Continent*>&);
        std::vector<Continent*> getContinents();

        void reinforce();
        void attack();
        void fortify();

        int getId() const;
        void setId(int id);

};

#endif