//
// Created by Yashar Dabiran on 2018-10-10.
//

#include <fstream>
#include <sstream>
#include <sys/types.h>
#include <dirent.h>
#include "mapLoader.h"
#include "../Map/riskException.h"

map_ptr MapLoader::createMapWithFileName(const std::string &fileName) {
    auto fileContent = loadFileWithName(MapsDirPath + fileName);

    map_ptr mapPtr = std::make_unique<Map>();

    // Different states: mapInfo, continents, countries
    std::string state = "none";

    // Reading the file content
    for (const std::string line: fileContent) {
        if (line.size() == 0)
            continue;

        // Changing the state
        if (line.find("[Map]") != std::string::npos) {
            state = "mapInfo";
            continue;
        }
        if (line.find("[Continents]") != std::string::npos) {
            state = "continents";
            continue;
        }
        if (line.find("[Territories]") != std::string::npos) {
            state = "countries";
            continue;
        }

        if (state == "continents") {
            addContinentToMap(mapPtr, line);
        } else if (state == "countries") {
            addCountryToMap(mapPtr, line);
        }
    }

    if (mapPtr->numberOfCountries() == 0)
        throw RiskException("There are no countries in the map file.");
    mapPtr->checkIfMapIsValid();

    return std::move(mapPtr);
}

std::vector<std::string> MapLoader::loadFileWithName(const std::string &fileName) {
    std::vector<std::string> fileContent;

    // Read each line from the file
    std::ifstream file(fileName);
    std::string line;
    while(std::getline(file, line)) {
        fileContent.push_back(line.substr(0, line.size()));
    }

    return fileContent;
}

void MapLoader::addContinentToMap(map_ptr &mapPtr, std::string line) {
    auto position = line.find('=');
    if (position == std::string::npos)
        throw RiskException("Continent name is not in the right format.");

    mapPtr->addContinent(line.substr(0, position));
}

void MapLoader::addCountryToMap(map_ptr &mapPtr, std::string info) {
    std::vector<std::string> dividedInfo;

    // Separate each string using delimiter ','
    std::istringstream ss(info);
    std::string token;
    while (std::getline(ss, token, ','))
        dividedInfo.push_back(token);

    if (dividedInfo.size() <= 4)
        throw RiskException("One of the countries does not have the correct format.");

    std::vector<std::string> adjList(dividedInfo.begin() + 4, dividedInfo.end());
    mapPtr->addCountry(dividedInfo[0], dividedInfo[3], adjList);
}

std::vector<std::string> MapLoader::getListOfAllMapFiles() {
    std::vector<std::string> fileNames;

    // Open directory
    DIR *dirp = opendir(MapsDirPath.c_str());
    struct dirent * dp;
    while ((dp = readdir(dirp)) != NULL) {
        // Check if the file is a .map file
        std::string name(dp->d_name);
        if (name.find(".map") != std::string::npos)
            fileNames.emplace_back(dp->d_name);
    }
    // Close directory
    closedir(dirp);
    return fileNames;
}

MapLoader::MapLoader(): MapsDirPath("Model/Maploader/Maps/") {}
