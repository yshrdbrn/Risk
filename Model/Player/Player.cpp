#include"Player.h"
#include "../Map/country.h"
#include <vector>



Player::Player(){};

Hand Player::getHand(){
    return hand ; 
}

void Player::setHand(Hand h){
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

void Player::setCountries(std::vector<Country*> c){
    countries = c;
}

void Player::attack(){
    std::cout << "Player is attacking.. " << endl ;
}

void Player::fortify(){
    std::cout << "begin fortfiying phase..." << endl ;

}

void Player:: reinforce(){
    std::cout << "begin reinforcing phase... " << endl;
}

string Player::getName() {
	return this->name;
}

void Player::setName(string name) {
	this->name = name;
}

void Player::addCountries(country_ptr object) {
	countries.push_back(object);
}

