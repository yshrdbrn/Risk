//
// Created by Yashar Dabiran on 2018-10-10.
//

#include <iostream>
#include <string>
#include "mapLoader.h"
#include "../Map/riskException.h"
#include "map"

int main() {
    MapLoader mapLoader;

<<<<<<< HEAD
    std::cout << "hello" << std::endl;
    std::string path = "../Model/Maploader/Maps/";

=======
>>>>>>> e33bc0c4537f3a9f7d1f73e4ef7af722b223f306
    try {
        map_ptr mapPtr = mapLoader.createMapWithFileName("WorldNotRightFormat.map");
        std::cout << "File is valid" << std::endl;
    } catch (RiskException &e) {
        std::cout << "Error on first file:" << std::endl;
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << std::endl;
        map_ptr mapPtr2 = mapLoader.createMapWithFileName("WorldNotConnected.map");
        std::cout << "File is valid" << std::endl;
    } catch (RiskException &e) {
        std::cout << "Error on second file:" << std::endl;
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << std::endl;
        map_ptr mapPtr3 = mapLoader.createMapWithFileName("World.map");
        std::cout << "File is valid" << std::endl;
    } catch (RiskException &e) {
        std::cout << "Error on third file:" << std::endl;
        std::cout << e.what() << std::endl;
    }
}
