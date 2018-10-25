//
// Created by Yashar Dabiran on 2018-10-04.
//

#include <unordered_map>
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


bool Continent::isConnected() {
    // Create the mark for dfs
    std::unordered_map<std::string, bool> mark;
    for (const country_ptr &countryPtr: countries)
        // Add each country inside the continent to mark and flag them as false
        mark[countryPtr->getName()] = false;

    dfs(countries[0], mark);

    // Check if dfs marked all of the countries
    for (auto &it : mark) {
        if (!it.second) {
            return false;
        }
    }

    return true;
}


void Continent::dfs(country_ptr node, std::unordered_map<std::string, bool> &mark) {
    mark[node->getName()] = true;

    for (const auto &t: node->getNeighbors()) {
        // If the neighbor is not marked
        if (containsCountry(t->getName()) && !mark[t->getName()])
            dfs(t, mark);
    }
}

bool Continent::containsCountry(std::string countryName) {
    for (const country_ptr &ptr: countries)
        if (ptr->getName() == countryName)
            return true;

    return false;
}
