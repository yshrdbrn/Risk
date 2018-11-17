//
// Created by Yashar Dabiran on 2018-11-17.
//

#include "Strategy.h"
#include "Player.h"
#include "../Map/continent.h"

int Strategy::giveArmiesToPlayer(Player *player) {
    auto countries = player->getCountries();

    std::cout << "begin reinforcing phase... " << endl;
    int armies = 3 ;

    //add number of armies based on number of countries owned
    if(countries.size()/3 > 3)
        armies = (countries.size()/3);


    //// Give Player extra armies if they own a continent

    // Map to mark which continents we already checked
    std::vector<std::string> continentMark;

    for (auto &country: countries) {
        auto continent = country->getContinent();
        // If we haven't checked this continent yet
        if (std::find(continentMark.begin(), continentMark.end(), continent->getName()) != continentMark.end()) {
            continentMark.push_back(continent->getName());
            if (continent->doesContinentBelongToPlayer(player))
                armies += continent->getControlValue();
        }
    }

    return armies;
}

