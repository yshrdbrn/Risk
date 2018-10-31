#include "Player.h"
#include "../Map/country.h"

int main()
{

    Country * c1 = new Country("c1");
    Country * c2 = new Country("c2") ;
    Country * c3 = new Country("c3") ;
    std::vector<Country*> c = {c1,c2, c3};
    Continent * continent1 = new Continent("Asia");
    Continent * continent2 = new Continent ("Africa");
    std::vector<Continent *> continents = {continent1,continent2};
    Player p1;
    p1.setCountries(c);
    p1.setContinents(continents);

    Hand h(0,0,0);
    p1.setHand(h);
	p1.attack();
	p1.fortify();
    p1.reinforce();
     

    return 0;
}

