#include "Player.h"
#include "../Map/country.h"



Player::Player(){};

Player::Player(int playerId): id(playerId) {}

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

int Player::getId() const {
    return id;
}

void Player::setId(int id) {
    Player::id = id;
}

