//
// Created by Yashar Dabiran on 2018-10-10.
//

#include <iostream>
#include "mapLoader.h"
#include "map"

int main() {
    MapLoader mapLoader;

    map_ptr mapPtr = mapLoader.createMapWithFileName("Maps/World.map");
    mapPtr->checkIfMapIsValid();
    std::cout << "map is valid" << std::endl;
}
