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


bool Continent::isConnected(std::unordered_map<country_ptr, std::vector<country_ptr> > &adjList) {
    std::unordered_map<country_ptr, bool> mark;
    for (const country_ptr countryPtr: countries)
        mark[countryPtr] = true;

    dfs(countries[0], mark, adjList);

    for (auto it = mark.begin(); it != mark.end() ; it++) {
        if (!it->second) {
            return false;
        }
    }

    return true;
}

void Continent::dfs(const country_ptr &node, std::unordered_map<country_ptr, bool> &mark,
        std::unordered_map<country_ptr, std::vector<country_ptr> > &adjList) {
    mark[node] = true;
    std::vector<country_ptr> adj = adjList[node];

    for (const auto &t: adj) {
        if (contains(t) and !mark[t])
            dfs(t, mark, adjList);
    }
}

bool Continent::contains(const country_ptr &countryPtr) {
    for (auto ptr: countries)
        if (ptr->getName() == countryPtr->getName())
            return true;

    return false;
}
