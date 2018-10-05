//
// Created by Yashar Dabiran on 2018-10-04.
//

#include "continent.h"

Continent::Continent(const std::string &name) : name(name) {}

bool Continent::operator==(const Continent &other) const {
    return name == other.name;
}

bool Continent::operator!=(const Continent &other) const {
    return !(other == *this);
}

void Continent::addCountry(country_ptr ptr) {
    countries.push_back(ptr);
}

const std::string &Continent::getName() const {
    return name;
}

int Continent::numberOfCountriesWithName(std::string name) {
    int counter = 0;
    for (const country_ptr &country: countries)
        if (country->getName() == name)
            counter++;

    return counter;
}

// TODO
bool Continent::isConnected() {
    return false;
}
