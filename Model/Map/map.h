#ifndef RISKGAME_MAP_H
#define RISKGAME_MAP_H

#include <vector>
#include <unordered_map>
#include <memory>
#include "country.h"
#include "continent.h"
#include "riskException.h"

typedef std::shared_ptr<Continent> continent_ptr;

class Map {
private:
    // Countries of the map
    std::vector<country_ptr> countries;

    // Continents of the map
    std::vector<continent_ptr> continents;

    /**
     * Checks if each country is in one continent
     * @return true if the above statement holds
     */
    bool isEachCountryInOneContinent();

    /**
     * Check if the whole map is connected
     * @return true if map is connected
     */
    bool isMapConnected();

    /**
     * Traverses the graph and marks the nodes that is has seen
     * @param node the vertex that it traverses at the moment
     * @param mark data structure that contains the nodes that we have seen
     */
    void dfs(country_ptr node, std::unordered_map<std::string, bool> &mark);

    /**
     * Checks if the continent given is connected or not
     * @param continent the continent object to be checked
     * @return true if the continent is connected
     */
    bool isConnectedForContinent(continent_ptr continent);

    /**
     * Checks if all of the continents in the map are connected
     * @return true if all of the continents are connected
     */
    bool areAllContinentsConnected();

    /**
     * Finds the continent object corresponding to the name.
     * It will return null if there is no continent with the name given.
     * @param name of the continent
     * @return shared_ptr to the continent object.
     *         null if there is no continent with the name given
     */
    continent_ptr findContinent(const std::string &name);

    /**
     * Finds the country corresponding to the name.
     * If it cannot find the country, it will create a new country with the given name
     * and adds it to the countries vector.
     * @param name of the country
     * @return shared_ptr to the country object.
     */
    country_ptr findCountry(const std::string &name);

public:
    /**
     * Adds a continent with the name given to the map
     * @param name of the continent
     */
    void addContinent(std::string name);

    /**
     * Adds a country with the information given to the map
     * @param name of the country
     * @param continent the country belongs to
     * @param adj the countries that are the neighbors of this country
     */
    void addCountry(std::string name, std::string continent, std::vector<std::string> adj);

    /**
     * Checks if the map is valid, that is:
     * 1. Each country belongs to exactly one continent
     * 2. Each continent is connected
     * 3. Map is connected
     *
     * @throw RiskException() if the map is not valid
     */
    void checkIfMapIsValid();

    /**
     * Returns the number of countries in the map
     * @return number of countries
     */
    int numberOfCountries();
};


#endif //RISKGAME_MAP_H
