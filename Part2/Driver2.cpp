//
// Created by Yashar Dabiran on 2018-10-10.
//

#include <iostream>
#include "mapLoader.h"
#include "../Part1/riskException.h"
#include "map"

int main() {
    MapLoader mapLoader;

    try {
        map_ptr mapPtr = mapLoader.createMapWithFileName("Maps/WorldNotRightFormat.map");
        std::cout << "File is valid" << std::endl;
    } catch (RiskException &e) {
        std::cout << "Error on first file:" << std::endl;
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << std::endl;
        map_ptr mapPtr2 = mapLoader.createMapWithFileName("Maps/WorldNotConnected.map");
        std::cout << "File is valid" << std::endl;
    } catch (RiskException &e) {
        std::cout << "Error on second file:" << std::endl;
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << std::endl;
        map_ptr mapPtr3 = mapLoader.createMapWithFileName("Maps/World.map");
        std::cout << "File is valid" << std::endl;
    } catch (RiskException &e) {
        std::cout << "Error on third file:" << std::endl;
        std::cout << e.what() << std::endl;
    }
}
