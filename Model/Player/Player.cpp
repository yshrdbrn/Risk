#include <algorithm>
#include "Player.h"
#include "../Map/continent.h"
#include <string>
#include <vector>
#include <exception>
#include <algorithm>




Player::Player(){};


Player::Player(int playerID, Strategy *strategy1) : id(playerID), strategy(strategy1){
    dice = new Dice();
}

Player::~Player() {
    delete dice;
}


Hand *Player::getHand(){
    return &hand;
}

void Player::setHand(Hand &h){
    hand = h;
}

Dice * Player::getDice(){
    return dice;
}

void Player::setDice(Dice * d){
    dice = d;
}

std::vector<country_ptr> Player::getCountries(){
    return countries;
}

void Player::setCountries(std::vector<country_ptr>& c){
    countries = c;
}

int Player::getId() const {
    return id;
}

void Player::setId(int id) {
    Player::id = id;
}




void Player::attack(State *state){
    strategy->performAttack(this, state);
}


void Player::fortify(State *state){
    strategy->performFortify(this, state);
}


void Player:: reinforce(State *state){
    strategy->performReinforce(this, state);
}




void Player::addCountries(country_ptr object) {
    countries.push_back(object);
}

void Player::countryNames() {

    if (this->countries.size()==0)
        cout <<"\n"<< this->getName() + " has no countries" << endl;

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

void Player::removeArmies(int armies) {
    this->hand.setArmies(this->hand.getArmies() - armies);
}


string Player::getName() {
    return this->name;
}

void Player::setName(string name) {
    this->name = name;
}

void Player::addCountry(country_ptr countryPtr) {
    countries.push_back(countryPtr);
}

void Player::removeCountry(country_ptr countryPtr) {
    for (auto it = countries.begin(); it != countries.end(); it++)
        if ((*it)->getName() == countryPtr->getName()) {
            countries.erase(it);
            break;
        }
}

int Player::whichCountryToPlaceOneArmyOn() {
    return strategy->whichCountryToPlaceOneArmyOn(this);
}

void Player::setStrategy(Strategy *strategy) {
    Player::strategy = strategy;
}
