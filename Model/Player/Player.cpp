#include "Player.h"
#include <string>
#include <map>
#include <exception>



Player::Player(){};

Player::Player(int playerId): id(playerId) {}

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
    std::cout << "begin reinforcing phase... " << endl;
        //number of armies is initially 3
        int armies = 3 ;

        //add number of armies based on number of countries owned
        if(countries.size()/3 > 3){
            armies = armies + (countries.size()/3-3);
        }

        //Map Continent names to int for "switch case"
        std::map<std::string, int > stringToIntMap ;

        //Initialize HashMap 
        stringToIntMap["Asia"]= 1;
        stringToIntMap["North America"] = 2;
        stringToIntMap["Europe"] = 3;
        stringToIntMap["Africa"] = 4;
        stringToIntMap["South America"]= 5;
        stringToIntMap["Australia"] = 6;

        //Give Player extra armies if they own a continent
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

        //Prompt Player to exchange cards for extra armies
        hand.exchange(armies);
        
         while(armies > 0){
            cout<< "You have " << armies << " armies to place " << endl;
            int armiesToPlace;
            std::string country_input;
            //prompt user tp select the number pf armies to place and check if they have enough armies
            cout << "please enter the number of armies you wish to place " << endl ;
            cin >> armiesToPlace ;
            if(armiesToPlace > armies){
                cout << "You don't have enough armies to place" << endl;
                continue;
            }
            else{
            cout << "Please enter the name of the country where you wish to place your armies: " << endl;
            cin >> country_input ;
            //iterate through "countries" vector to check if country is owned by the player
            std::vector<Country*> :: iterator iter;
            bool countryIsOwned = false;
            for(iter=countries.begin() ; iter!=countries.end() ; iter++){
                if((*iter)->getName() == country_input){
                    countryIsOwned=true;
                    (*iter)->AddNumOfArmies(armiesToPlace);
                    armies = armies - armiesToPlace;
                    continue;
                }
            }
            if(countryIsOwned){
                cout << "Placed " << armiesToPlace << " armies on " << country_input << "." <<endl;
            }
            else{
                cout << "Country name in not valid..." << endl;
                continue;
            } 

            }
        }

}
int Player::getId() const {
    return id;
}

void Player::setId(int id) {
    Player::id = id;
}

