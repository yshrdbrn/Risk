//
// Created by Yashar Dabiran on 2018-10-04.
//

#ifndef RISKGAME_COUNTRY_H
#define RISKGAME_COUNTRY_H

#include <string>
#include <vector>

class Continent;

class Player;

class Country {
private:
    // Name of the country, which is unique
    std::string name;

    // Vector of neighbors of the country
    std::vector<std::shared_ptr<Country>> neighbors;

    // The continent this country belongs to
    std::shared_ptr<Continent> continent;

	Player* player;

	int armies = 0;

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

	void setArmies(int armies);

	int getArmies();

	void incrementArmies(int armies);
};


#endif //RISKGAME_COUNTRY_H
