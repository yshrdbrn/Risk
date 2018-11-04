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

std::vector<country_ptr> Player::getCountries(){
    return countries;
}

void Player::setCountries(std::vector<country_ptr> c){
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

void Player::countryNames() {
	
	if (this->countries.size()==0)
		cout << this->getName() + " has no countries" << endl;
	
	else {
cout << "\nThe countries of " + this->getName() + " are :" << endl;

		for (int i = 0;i < this->countries.size();i++) {
			cout << this->countries[i]->getName() << endl;
		}
	}
}

void Player::setArmies(int armies) {
	this->hand.setArmies(armies);
}

int Player::getArmies() {
	return this->hand.getArmies();
}

