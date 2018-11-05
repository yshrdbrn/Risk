#include "Player.h"
#include "../Map/country.h"
#include "../Maploader/mapLoader.h"
#include "../../Controller/GameEngine.h"



int main()
{
   /*GameEngine gameEngine;
    gameEngine.initGame();

    // Each player will get their turn:
    gameEngine.setOwnershipOfCountriesToRandomPlayers();
    gameEngine.mainLoop(1);*/


   /* Player * p1 = new Player();
    Player * p2 = new Player();
    typedef std::unique_ptr<Map> map_ptr;
    MapLoader maploader;
    const std::string path = "../Model//Maploader/Maps/World.map";
    map_ptr map = maploader.createMapWithFileName(path);
    map->checkIfMapIsValid();
    std::vector<country_ptr>::iterator iter;
    std::vector<country_ptr> countries = map->getCountries();
    for(iter=countries.begin(); iter != countries.end() ; iter++){
       int  randomInt = (int)((4 * rand() / (RAND_MAX + 1.0)) + 1);
        (*iter)->setOwner(p1);
        (*iter)->addNumOfArmies(randomInt);
    }

    cout << countries[5]->getName() << endl;
    */




    Player * p1 = new Player(1);
    Player* p2 = new Player(2);
    country_ptr usa = std::make_shared<Country>("USA");
    country_ptr canada =std::make_shared<Country>("Canada");
    country_ptr alaska =std::make_shared<Country>("Alaska");
    country_ptr france = std::make_shared<Country>("France");
    country_ptr germany = std::make_shared<Country>("Germany");
    country_ptr england = std::make_shared<Country>("England");

    
    std::vector<country_ptr> usNeighbors{canada , alaska};
    usa->setNeighbors(usNeighbors);
    std::vector<country_ptr> canadaNeighbors{usa , alaska};
    canada->setNeighbors(canadaNeighbors);
    std::vector<country_ptr> alaskaNeighbors{usa , canada};
    alaska->setNeighbors(alaskaNeighbors);
    std::vector<country_ptr>franceNeighbors{england , germany};
    france->setNeighbors(franceNeighbors);
    std::vector<country_ptr>englandNeighbors{france, germany};
    england->setNeighbors(englandNeighbors);
    std::vector<country_ptr>germanyNeiyeghbors{france,england};
    germany->setNeighbors(germanyNeiyeghbors);

    std::vector<country_ptr> countries{usa , canada , alaska , france , germany, england};

    std::vector<country_ptr>::iterator iter;
    for(iter=countries.begin(); iter != countries.end() ; iter++){
       int  randomInt = (int)((4 * rand() / (RAND_MAX + 1.0)) + 1);
        (*iter)->addNumOfArmies(randomInt);
    }

    std::vector<country_ptr> p1Countries{usa , canada , france , germany};
    std::vector<country_ptr> p2Countries{england, alaska};

    p1->setCountries(p1Countries);
    p2->setCountries(p2Countries);
    usa->setOwner(p1);
    canada->setOwner(p1);
    france->setOwner(p1);
    germany->setOwner(p1);
    england->setOwner(p2);
    alaska->setOwner(p2);

    p1->reinforce();
    p1->attack();
    p1->fortify();




   /* Hand hand(2,2,2);
    p1.setHand(hand);
    std::shared_ptr<Country> usa = new Country("USA");
    std::shared_ptr<Country> france = new Country("France");
    std::shared_ptr<Country> brazil = new Country("Brazil");
    Country * alaska = new Country("Alaska");
    Country * canada = new Country("Canada");
    std::vector<Country*> c1{brazil , canada , alaska};
    std::vector<Country*> Canada_neighbors{usa,alaska};
    canada->s
    p1.setCountries(c1);
	france->addNumOfArmies(5);
    alaska->addNumOfArmies(4);
    canada->addNumOfArmies(4);
    usa->addNumOfArmies(1);
	p1.attack();
    p1.reinforce();
    p1.fortify();*/





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

