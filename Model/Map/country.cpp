//
// Created by Yashar Dabiran on 2018-10-04.
//

#include "country.h"
#include "../Player/Player.h"

Country::Country(const std::string &name) : name(name) ,numOfArmies(0) {}

bool Country::operator==(const Country &other) const {
    return name == other.name;
}

bool Country::operator!=(const Country &other) const {
    return !(other == *this);
}

const std::string &Country::getName() const {
    return name;
}

void Country::addNeighbor(const std::shared_ptr<Country> &countryPtr) {
    neighbors.push_back(countryPtr);
}

void Country::setContinent(const std::shared_ptr<Continent> &cont) {
    this->continent = cont;
}

std::vector<std::shared_ptr<Country>>& Country::getNeighbors() {
    return neighbors;
}


int Country::getNumOfArmies(){
    return numOfArmies;
}

void Country::addNumOfArmies(int armies){
    numOfArmies += armies;
}

void Country::removeNumOfArmies(int armies){
    numOfArmies -= armies;
}

void Country::setOwner(Player *player) {
    owner = player;
}

Player *Country::getOwner() {
    return owner;
}

void Country::setNeighbors(std::vector<std::shared_ptr<Country>>& n){
    neighbors=n;
}

void Country::incrementArmies(int armies) {
    numOfArmies += armies;
}
