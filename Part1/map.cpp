//
// Created by Yashar Dabiran on 2018-10-04.
//

#include "map.h"

bool Map::isEachCountryInOneContinent() {
    // TODO
    return false;
}

bool Map::isMapConnected() {
    // TODO
    return false;
}

bool Map::isConnectedForContinent(continent_ptr continent) {
    // TODO
    return false;
}

bool Map::isMapValid() {
    if (!isEachCountryInOneContinent()) throw MapException("one country belongs to more than one continent.");
    if (!isMapConnected()) throw MapException("Map is not connected");
    for (const continent_ptr &continent: continents) {
        if (!continent->isConnected())
            throw MapException("One of the continents not connected.");
    }

    // TODO
    return false;
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

