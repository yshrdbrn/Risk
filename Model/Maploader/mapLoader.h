//
// Created by Yashar Dabiran on 2018-10-10.
//

#ifndef RISKGAME_MAPLOADER_H
#define RISKGAME_MAPLOADER_H

#include <vector>
#include <string>
#include "../Map/map.h"

typedef std::unique_ptr<Map> map_ptr;

class MapLoader {
private:
    const std::string MapsDirPath;

    /**
     * Loads the map with the given file name
     * @param fileName the name of map file
     * @return all the lines in the file in a vector
     */
    std::vector<std::string> loadFileWithName(const std::string &fileName);

    /**
     * Adds a continent to the map object it has
     * @param mapPtr the map to add the continent in
     * @param line description of the continent
     */
    void addContinentToMap(map_ptr &mapPtr, std::string line);

    /**
     * Adds a country to the map object it has
     * @param mapPtr the map to add the country in
     * @param info description of the country
     */
    void addCountryToMap(map_ptr &mapPtr, std::string info);

public:
    MapLoader();

    /**
     * Creates a map object out of the map file with the name given
     * @param fileName the name of the map file
     * @return the pointer to the map
     * @throw RiskException() if the map file is not valid
     */
    map_ptr createMapWithFileName(const std::string &fileName);

    /**
     * This function will traverse all the .map files in "{PROJECT_ROOT}/Model/Maploader/Maps".
     * It will return the name of all the map files
     * @return vector of all the map names
     */
    std::vector<std::string> getListOfAllMapFiles();
};


#endif //RISKGAME_MAPLOADER_H
