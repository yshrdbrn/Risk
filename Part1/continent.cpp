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


bool Continent::isConnected(std::unordered_map<std::string, std::vector<std::string> > &adjList) {
    std::unordered_map<std::string, bool> mark;
    for (const country_ptr &countryPtr: countries)
        mark[countryPtr->getName()] = false;

    dfs(countries[0]->getName(), mark, adjList);

    for (auto &it : mark) {
        if (!it.second) {
            return false;
        }
    }

    return true;
}

void Continent::dfs(std::string node, std::unordered_map<std::string, bool> &mark,
        std::unordered_map<std::string, std::vector<std::string> > &adjList) {
    mark[node] = true;
    std::vector<std::string> &adj = adjList[node];

    for (const auto &t: adj) {
        if (contains(t) and !mark[t])
            dfs(t, mark, adjList);
    }
}

bool Continent::contains(std::string countryName) {
    for (const country_ptr &ptr: countries)
        if (ptr->getName() == countryName)
            return true;

    return false;
}
