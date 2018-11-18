#include "Player.h"
#include "../Map/country.h"
#include "../Maploader/mapLoader.h"
#include "../../Controller/GameEngine.h"



int main()
{
   

    Player * p1 = new Player();
    Player* p2 = new Player();
    Dice * d1 = new Dice();
    Dice * d2 = new Dice();
    p1->setDice(d1);
    p2->setDice(d2);
    Hand hand(2,2,2);
    country_ptr usa = std::make_shared<Country>(Country("USA"));
    country_ptr canada =std::make_shared<Country>(Country("Canada"));
    country_ptr alaska =std::make_shared<Country>(Country("Alaska"));
    country_ptr france = std::make_shared<Country>(Country("France"));
    country_ptr germany = std::make_shared<Country>(Country("Germany"));
    country_ptr england = std::make_shared<Country>(Country("England"));
    country_ptr brazil = std::make_shared<Country>(Country("Brazil"));
    country_ptr peru = std::make_shared<Country>(Country("Peru"));
    country_ptr mexico = std::make_shared<Country>(Country("Mexico"));
    country_ptr china = std::make_shared<Country>(Country("China"));
    country_ptr india = std::make_shared<Country>(Country("India"));
    country_ptr tokyo = std::make_shared<Country>(Country("Tokyo"));
    country_ptr australia = std::make_shared<Country>(Country("Australia"));
    country_ptr russia = std::make_shared<Country>(Country("Russia"));

    
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

    std::vector<country_ptr> countries{usa,canada,alaska,france,germany,england,brazil,peru,china,india,tokyo,australia,russia,mexico};

    std::vector<country_ptr>::iterator iter;
    for(iter=countries.begin(); iter != countries.end() ; iter++){
       int  randomInt = (int)((4 * rand() / (RAND_MAX + 1.0)) + 1);
        (*iter)->addNumOfArmies(3);
    }

    std::vector<country_ptr> p1Countries{usa,france,germany,france,england,brazil,peru,china,india,tokyo,australia,russia,mexico,alaska};
    std::vector<country_ptr> p2Countries{england,canada};

    p1->setCountries(p1Countries);
    p2->setCountries(p2Countries);
    usa->setOwner(p1);
    canada->setOwner(p2);
    france->setOwner(p1);
    germany->setOwner(p1);
    england->setOwner(p2);
    alaska->setOwner(p1);

   






   
    

    return 0;
}

