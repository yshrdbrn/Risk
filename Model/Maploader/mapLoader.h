//
// Created by Yashar Dabiran on 2018-10-10.
//

#ifndef RISKGAME_MAPLOADER_H
#define RISKGAME_MAPLOADER_H

#include <vector>
#include <string>
#include "../Model/Map/map.h"

typedef std::unique_ptr<Map> map_ptr;

class MapLoader {
private:
    std::vector<std::string> loadFileWithName(const std::string &fileName);

    void addContinentToMap(map_ptr &mapPtr, std::string line);

    void addCountryToMap(map_ptr &mapPtr, std::string info);

public:
    map_ptr createMapWithFileName(const std::string &fileName);
};


#endif //RISKGAME_MAPLOADER_H
