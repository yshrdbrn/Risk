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

        if (counter != 1)
            return false;
    }

    return true;
}

bool Map::isMapConnected() {
    std::unordered_map<country_ptr, bool> mark;
    for (const country_ptr &countryPtr: countries)
        mark[countryPtr] = true;

    dfs(countries[0], mark);

    for (auto &it : mark) {
        if (!it.second) {
            throw MapException("Map is not connected");
        }
    }

    return true;
}

bool Map::isConnectedForContinent(continent_ptr continent) {
    return continent->isConnected(adjList);
}

bool Map::areAllContinentsConnected() {
    for(const continent_ptr &continentPtr: continents)
        if (!isConnectedForContinent(continentPtr))
            return false;

    return true;
}

bool Map::isMapValid() {
    if (!isEachCountryInOneContinent()) throw MapException("one country belongs to more than one continent.");
    if (!isMapConnected()) throw MapException("Map is not connected");
    if (!areAllContinentsConnected()) throw MapException("One of the continents not connected.");

    return true;
}

void Map::addContinent(std::string name) {
    if (findContinent(name) != nullptr)
        throw MapException("Continent already exists");

    continents.push_back(std::make_shared<Continent>(name));
}

void Map::addCountry(std::string name, std::string continent, std::vector<std::string> adj) {
    // Check if continent exists
    continent_ptr cnt = findContinent(continent);
    if (cnt == nullptr) {
        char buffer[100];
        sprintf(buffer, "Continent %s is not found for country %s.", continent.data(), name.data());
        throw MapException(buffer);
    }

    // Find or create the Country object
    country_ptr ptr = findCountry(name);
    if (ptr == nullptr)
        ptr = std::make_shared<Country>(name);

    // Create Country vector of adjacent countries
    std::vector<country_ptr> adjCountries;
    for (const std::string &adjName: adj) {
        country_ptr adjPtr = findCountry(adjName);
        if (adjPtr == nullptr)
            adjPtr = std::make_shared<Country>(adjName);
        adjCountries.push_back(adjPtr);
    }

    // Update map properties
    adjList[ptr] = adjCountries;
    cnt->addCountry(ptr);
    countries.push_back(ptr);
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
    for(const country_ptr &ptr: countries)
        if (ptr->getName() == name) {
            found = ptr;
            break;
        }

    return found;
}

void Map::dfs(const country_ptr &node, std::unordered_map<country_ptr, bool> &mark) {
    mark[node] = true;
    std::vector<country_ptr> adj = adjList[node];

    for (const auto &t: adj) {
        if (!mark[t])
            dfs(t, mark);
    }
}

