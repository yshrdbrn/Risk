//
// Created by Yashar Dabiran on 2018-10-04.
//

#include <unordered_map>
#include "map.h"

bool Map::isEachCountryInOneContinent() {
    for (const country_ptr &countryPtr: countries) {
        int counter = 0;
        for (const continent_ptr &continentPtr: continents)
            counter += continentPtr->numberOfCountriesWithName(countryPtr->getName());

        // This country either not exists in any continent or exists in more than one continent
        if (counter != 1)
            return false;
    }

    return true;
}

bool Map::isMapConnected() {
    std::unordered_map<std::string, bool> mark;
    for (const country_ptr &countryPtr: countries)
        mark[countryPtr->getName()] = false;

    dfs(countries[0], mark);

    // Check if dfs traversed all the countries
    for (auto &it : mark) {
        if (!it.second) {
            throw RiskException("Map is not connected");
        }
    }

    return true;
}

bool Map::isConnectedForContinent(continent_ptr continent) {
    return continent->isConnected();
}

bool Map::areAllContinentsConnected() {
    for(const continent_ptr &continentPtr: continents)
        if (!isConnectedForContinent(continentPtr))
            return false;

    return true;
}

void Map::checkIfMapIsValid() {
    if (!isEachCountryInOneContinent()) throw RiskException("one country belongs to more than one continent.");
    if (!isMapConnected()) throw RiskException("Map is not connected");
    if (!areAllContinentsConnected()) throw RiskException("One of the continents not connected.");
}

void Map::addContinent(std::string name, int controlValue) {
    if (findContinent(name) != nullptr)
        throw RiskException("Continent already exists");

    continents.push_back(std::make_shared<Continent>(name, controlValue));
}

void Map::addCountry(std::string name, std::string continent, std::vector<std::string> adj) {
    // Check if continent exists
    continent_ptr cnt = findContinent(continent);
    if (cnt == nullptr) {
        char buffer[100];
        sprintf(buffer, "Continent %s is not found for country %s.", continent.data(), name.data());
        throw RiskException(buffer);
    }

    // Find or create the Country object
    country_ptr ptr = findCountry(name);
    ptr->setContinent(cnt);

    // Update map properties
    for (auto &adjCountry: adj) {
        auto adjPtr = findCountry(adjCountry);
        ptr->addNeighbor(adjPtr);
    }

    cnt->addCountry(ptr);
}


continent_ptr Map::findContinent(const std::string &name) {
    continent_ptr found = nullptr;
    for(const continent_ptr &ptr: continents)
        if (ptr->getName() == name) {
            found = ptr;
            break;
        }

    return found;
}

country_ptr Map::findCountry(const std::string &name) {
    country_ptr found = nullptr;
    for(const country_ptr &ptr: countries) {
        if (ptr->getName() == name) {
            found = ptr;
            break;
        }
    }

    if (found == nullptr) {
        found = std::make_shared<Country>(name);
        countries.push_back(found);
    }
    return found;
}

void Map::dfs(country_ptr node, std::unordered_map<std::string, bool> &mark) {
    mark[node->getName()] = true;

    for (const auto &t: node->getNeighbors()) {
        if (!mark[t->getName()])
            dfs(t, mark);
    }
}


int Map::numberOfCountries() {
    return (int)countries.size();
}

Player *Map::ownerOfAllCountries() {
    Player *winner = countries[0]->getOwner();

    for(auto &country: countries) {
        if (winner->getId() != country->getOwner()->getId())
            return nullptr;
    }

    return winner;
}


const vector<country_ptr> Map::getCountries() const {

    return countries;
}

