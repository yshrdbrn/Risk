//
// Created by Yashar Dabiran on 2018-10-04.
//

#ifndef RISKGAME_COUNTRY_H
#define RISKGAME_COUNTRY_H

#include <string>
#include <vector>

class Continent;

class Country {
private:
    std::string name;

    std::vector<std::shared_ptr<Country>> neighbors;

    std::shared_ptr<Continent> continent;

public:
    explicit Country(const std::string &name);

    const std::string &getName() const;

    void addNeighbor(const std::shared_ptr<Country> &countryPtr);

    void setContinent(const std::shared_ptr<Continent> &cont);

    std::vector<std::shared_ptr<Country>> getNeighbors();

    bool operator==(const Country &other) const;

    bool operator!=(const Country &other) const;
};


#endif //RISKGAME_COUNTRY_H
