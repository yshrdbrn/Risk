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

// Returns the number of countries in the countries list with the same name as the input
int Continent::numberOfCountriesWithName(std::string name) {
    int counter = 0;
    for (const country_ptr &country: countries)
        if (country->getName() == name)
            counter++;

    return counter;
}


// Returns if this continent is connected
bool Continent::isConnected() {
    std::unordered_map<std::string, bool> mark;
    for (const country_ptr &countryPtr: countries)
        mark[countryPtr->getName()] = false;

    dfs(countries[0], mark);

    for (auto &it : mark) {
        if (!it.second) {
            return false;
        }
    }

    return true;
}

// DFS to traverse the continent graph
void Continent::dfs(country_ptr node, std::unordered_map<std::string, bool> &mark) {
    mark[node->getName()] = true;

    for (const auto &t: node->getNeighbors()) {
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
