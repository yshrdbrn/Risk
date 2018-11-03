#include "Player.h"
#include "../Map/country.h"
#include "../Maploader/mapLoader.h"



int main()
{
    //Create Map and check if it's valid
    typedef std::unique_ptr<Map> map_ptr;
    MapLoader  maploader;
    const std::string path = "../Model/Maploader/Maps/World.map";
     map_ptr map = maploader.createMapWithFileName(path);
     map->checkIfMapIsValid();

    //Create player
    Player p1;


    //Set the players Hand
    Hand hand(2,2,2);
    p1.setHand(hand);

    Country * brazil = new Country("Brazil");
    Country * alaska = new Country("Alaska");
    Country * canada = new Country("Canada");
    std::vector<Country*> c1{brazil , canada , alaska};
    p1.setCountries(c1);
    p1.reinforce();






            /*check if country name is valid
            ---------------------------------------------------------------------------------------
            *

            //create iterator
            std::vector<std::shared_ptr<Country>>:: iterator iter;

            //assign reference "countries" to countries container in map
            std::vector<country_ptr> & countries =  map->getCountries();

            //iterate through the vector to find a match
            bool foundMatch = false;
            for(iter=countries.begin() ; iter!=countries.end() ; iter++){
                if ((*iter)->getName() == country_input){
                    foundMatch=true;
                    continue;
                } 
            }            
            if(foundMatch){
                cout << "country is valid. Thank you!" << endl ;
            }
            else{
                cout << "country is not valid!"<< endl;
            }
            /* End: check if country is valid
            -------------------------------------------------------------------------------------
            */

    return 0;
}

