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
    std::vector<country_ptr> countries;

    std::string name;

    void dfs(country_ptr node, std::unordered_map<std::string, bool> &mark);

    bool containsCountry(std::string countryName);

public:
    explicit Continent(const std::string &name);

    bool operator==(const Continent &other) const;

    bool operator!=(const Continent &other) const;

    void addCountry(country_ptr ptr);

    const std::string &getName() const;

    int numberOfCountriesWithName(std::string name);

    bool isConnected();
};


#endif //RISKGAME_CONTINENT_H
