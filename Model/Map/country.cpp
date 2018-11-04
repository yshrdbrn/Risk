//
// Created by Yashar Dabiran on 2018-10-04.
//

#include "country.h"

Country::Country(const std::string &name) : name(name) {}

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

std::vector<std::shared_ptr<Country>> Country::getNeighbors() {
    return neighbors;
}

void Country:: setArmies(int armies) {
	this->armies = armies;
}

int Country:: getArmies() {
	return this->armies;
}

void Country::incrementArmies(int armies) {
	this->armies = this->armies + armies;
}
