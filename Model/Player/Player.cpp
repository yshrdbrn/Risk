#include "Player.h"
#include <string>
#include <map>



Player::Player(){};

Hand Player::getHand(){
    return hand ; 
}

void Player::setHand(Hand &h){
    hand = h;
}

Dice Player::getDice(){
    return dice;
}

void Player::setDice(Dice d){
    dice = d;
}

std::vector<Country *> Player::getCountries(){
    return countries;
}

void Player::setCountries(std::vector<Country*>& c){
    countries = c;
}

void Player::setContinents(std::vector<Continent*>& c){
    continents = c;
}

std::vector<Continent*> Player::getContinents(){
    return continents;
}

void Player::attack(){
    //std::cout << "Player is attacking.. " << endl ;
}

void Player::fortify(){
    //std::cout << "begin fortfiying phase..." << endl ;

}
//Reinforce method
void Player:: reinforce(){
    std::cout << "begin reinforcing phaseee... " << endl;
        //number of armies is initially 3
        int armies = 3 ;
        if(countries.size()/3 > 3){
            armies = armies + (countries.size()/3-3);
        };


        std::map<std::string, int > stringToIntMap ;

        //Initialize Map 
        stringToIntMap["Asia"]= 1;
        stringToIntMap["North America"] = 2;
        stringToIntMap["Europe"] = 3;
        stringToIntMap["Africa"] = 4;
        stringToIntMap["South America"]= 5;
        stringToIntMap["Australia"] = 6;

        if(continents.size() != 0) {
            for (int i = 0; i < continents.size(); i++) {
                switch (stringToIntMap[continents[i]->getName()]) {
                    case (1) :
                        armies = armies + 7;
                        break;
                    case (2) :
                        armies = armies + 5;
                        break;
                    case (3) :
                        armies = armies + 4;
                        break;
                    case (4) :
                        armies = armies + 3;
                        break;
                    case (5) :
                        armies = armies + 2;
                        break;
                    case (6) :
                        armies = armies + 2;
                        break;
                }
            }

        }

        hand.exchange(armies);

        cout<< "please assign your " << armies << " armies" << endl;
    }


