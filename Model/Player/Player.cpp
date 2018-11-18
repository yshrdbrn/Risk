#include <algorithm>
#include "Player.h"
#include "../Map/continent.h"
#include <string>
#include <vector>
#include <exception>
#include <algorithm>



//Default constructor
Player::Player(){};

//Constructor
Player::Player(int playerID, Strategy *strategy1 , Dice * dice , Hand * hand, PhaseView * view) : id(playerID), strategy(strategy1), dice(dice) , hand(hand) , view(view){
    registerObserver(view);
}

//HAnd getter
Hand *Player::getHand(){
    return hand;
}
//HAnd setter
void Player::setHand(Hand *h){
    hand = h;
}

//Dice getter 
Dice * Player::getDice(){
    return dice;
}

//Dice setter
void Player::setDice(Dice * d){
    dice = d;
}

//countries getter
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


//Method to start turn
void Player::startturn(){
notifyObservers();
reinforce();
attack();
fortify();

}

//Attack method
void Player::attack(){
    message ="Player" + to_string(id)+ "'s attack phase";
   notifyObservers();
    strategy->performAttack(this);
    view->clear();
}

//fortify method
void Player::fortify(){
    message = "Player" + to_string(id) + "'s fortifying phase";
   notifyObservers();
    strategy->performFortify(this);
    view->clear();
}

//reinforce method
void Player::reinforce(){
    message= "Player" + to_string(id) +"'s reinforcing phase";
    notifyObservers();
    strategy->performReinforce(this);
    view->clear();
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
    this->hand->setArmies(armies);
}

int Player::getArmies() {
    return this->hand->getArmies();
}

void Player::removeArmies(int armies) {
    this->hand->setArmies(this->hand->getArmies() - armies);
}


string Player::getName() {
    return this->name;
}

void Player::setName(string name) {
    this->name = name;
}

//Notifying the view of events
void Player::notifyObservers(){
    view->update(message);
}

//setting the event message
void Player::setMessage(std::string m){
    message = m;
    notifyObservers();
}