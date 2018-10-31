//
// Created by Yashar Dabiran on 2018-10-04.
//
#include <iostream>
#include <vector>
#include "map.h"
#include "riskException.h"

int main() {
    // Invalid map
    // One country is in two continents
    Map map1;
    map1.addContinent("America");
    map1.addContinent("Europe");
    std::vector<std::string> x, y;
    map1.addCountry("sample", "America", x);
    map1.addCountry("sample", "Europe", y);
    try {
        map1.checkIfMapIsValid();
        std::cout << "First map is valid." << std::endl;
    } catch (RiskException &e) {
        std::cout << "Error on first map:" << std::endl;
        std::cout << e.what() << std::endl;
    }


    // Invalid map
    // Map is not connected
    std::cout << std::endl;
    Map map2;
    map2.addContinent("America");
    map2.addContinent("Europe");
    x.emplace_back("city2");
    y.emplace_back("city1");
    std::vector<std::string> z;
    map2.addCountry("city1", "America", x);
    map2.addCountry("city2", "Europe", y);
    map2.addCountry("city3", "Europe", z);
    try {
        map2.checkIfMapIsValid();
        std::cout << "Second map is valid." << std::endl;
    } catch (RiskException &e) {
        std::cout << "Error on second map:" << std::endl;
        std::cout << e.what() << std::endl;
    }


    // Invalid map
    // Component is not connected
    std::cout << std::endl;
    Map map3;
    map3.addContinent("America");
    map3.addContinent("Europe");
    x.clear();
    y.clear();
    z.clear();
    x.emplace_back("city2");
    x.emplace_back("city3");
    y.emplace_back("city1");
    z.emplace_back("city1");
    map3.addCountry("city1", "America", x);
    map3.addCountry("city2", "Europe", y);
    map3.addCountry("city3", "Europe", z);
    try {
        map3.checkIfMapIsValid();
        std::cout << "Third map is valid." << std::endl;
    } catch (RiskException &e) {
        std::cout << "Error on third map:" << std::endl;
        std::cout << e.what() << std::endl;
    }


    // Valid map
    std::cout << std::endl;
    Map map4;
    map4.addContinent("America");
    map4.addContinent("Europe");
    x.clear();
    y.clear();
    z.clear();
    x.emplace_back("city2");
    y.emplace_back("city1");
    y.emplace_back("city3");
    z.emplace_back("city2");
    map4.addCountry("city1", "America", x);
    map4.addCountry("city2", "Europe", y);
    map4.addCountry("city3", "Europe", z);
    try {
        map4.checkIfMapIsValid();
        std::cout << "Forth map is valid." << std::endl;
    } catch (RiskException &e) {
        std::cout << "Error on forth map:" << std::endl;
        std::cout << e.what() << std::endl;
    }

	std::cout << map4.numberOfCountries() <<std:: endl;
	std::cin.get();
	std::cin.get();
}