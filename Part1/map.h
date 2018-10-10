#ifndef RISKGAME_MAP_H
#define RISKGAME_MAP_H

#include <vector>
#include <unordered_map>
#include "country.h"
#include "continent.h"
#include "riskException.h"

typedef std::shared_ptr<Continent> continent_ptr;

class Map {
private:
    std::unordered_map<std::string, std::vector<std::string> > adjList;

    std::vector<country_ptr> countries;

    std::vector<continent_ptr> continents;

    bool isEachCountryInOneContinent();

    bool isMapConnected();

    void dfs(std::string node, std::unordered_map<std::string, bool> &mark);

    bool isConnectedForContinent(continent_ptr continent);

    bool areAllContinentsConnected();

    continent_ptr findContinent(const std::string &name);

    country_ptr findCountry(const std::string &name);

public:
    void addContinent(std::string name);

    void addCountry(std::string name, std::string continent, std::vector<std::string> adj);

    bool isMapValid();
};


#endif //RISKGAME_MAP_H
