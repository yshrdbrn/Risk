//
// Created by Yashar Dabiran on 2018-10-04.
//

#ifndef RISKGAME_COUNTRY_H
#define RISKGAME_COUNTRY_H

#include <string>
#include <vector>
#include <memory>

class Continent;

class Country {
private:
    // Name of the country, which is unique
    std::string name;

    // Vector of neighbors of the country
    std::vector<std::shared_ptr<Country>> neighbors;

    // The continent this country belongs to
    std::shared_ptr<Continent> continent;

    //Player who own the country
    

    //number of armies placed on country
    int numOfArmies;


public:
    explicit Country(const std::string &name);

    const std::string &getName() const;

    /*
     * Adds a country to the neighbors vector
     */
    void addNeighbor(const std::shared_ptr<Country> &countryPtr);

    /*
     * Sets continent for the country
     */
    void setContinent(const std::shared_ptr<Continent> &cont);

    /*
     * Returns the vector containing the neighbors of this country
     */
    std::vector<std::shared_ptr<Country>> getNeighbors();

    bool operator==(const Country &other) const;

    bool operator!=(const Country &other) const;

    int getNumOfArmies();

    void AddNumOfArmies(int);
};


#endif //RISKGAME_COUNTRY_H
