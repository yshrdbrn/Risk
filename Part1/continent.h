//
// Created by Yashar Dabiran on 2018-10-04.
//

#ifndef RISKGAME_CONTINENT_H
#define RISKGAME_CONTINENT_H

#include <vector>
#include <unordered_map>
#include "country.h"

typedef std::shared_ptr<Country> country_ptr;

class Continent {
private:
    std::vector<country_ptr> countries;

    std::string name;

    void dfs(const country_ptr &node, std::unordered_map<country_ptr, bool> &mark,
            std::unordered_map<country_ptr, std::vector<country_ptr> > &adjList);

    bool contains(const country_ptr &countryPtr);

public:
    explicit Continent(const std::string &name);

    bool operator==(const Continent &other) const;

    bool operator!=(const Continent &other) const;

    void addCountry(country_ptr ptr);

    const std::string &getName() const;

    int numberOfCountriesWithName(std::string name);

    bool isConnected(std::unordered_map<country_ptr, std::vector<country_ptr> > &adjList);
};


#endif //RISKGAME_CONTINENT_H
