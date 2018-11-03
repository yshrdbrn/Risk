//
// Created by Yashar Dabiran on 2018-10-04.
//

#ifndef RISKGAME_CONTINENT_H
#define RISKGAME_CONTINENT_H

#include <vector>
#include <unordered_map>
#include <memory>
#include "country.h"

typedef std::shared_ptr<Country> country_ptr;

class Continent {
private:

    // All the countries that belong to the continent
    std::vector<country_ptr> countries;

    std::string name;


    /**
     * Traverses the graph of the countries inside the continent
     * @param node the node to traverse
     * @param mark the map that contains which nodes we have seen so far
     */
    void dfs(country_ptr node, std::unordered_map<std::string, bool> &mark);

    /**
     * Checks if the country is in the continent
     * @param countryName to check
     * @return true if the country is in the continent
     */
    bool containsCountry(std::string countryName);

public:
    explicit Continent(const std::string &name);

    bool operator==(const Continent &other) const;

    bool operator!=(const Continent &other) const;

    /**
     * Adds a country to its set of countries
     * @param ptr pointer to the country belonging to this continent
     */
    void addCountry(country_ptr ptr);

    const std::string &getName() const;

    /**
     * Counts the number of countries inside this continent with the name given
     * @param name of the country
     * @return number of countries with the name
     */
    int numberOfCountriesWithName(std::string name);

    /**
     * Checks if the continent is connected or not
     * @return true if the continent is connected
     */
    bool isConnected();
};


#endif //RISKGAME_CONTINENT_H
