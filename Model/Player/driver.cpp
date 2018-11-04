#include "Player.h"
#include "../Map/country.h"

int main()
{

	country_ptr c1 = std::make_shared<Country>("usa");
	country_ptr c2 = std::make_shared<Country>("china");
	country_ptr c3 = std::make_shared<Country>("france");
    std::vector<country_ptr> c = {c1,c2, c3};
    Player p1;
    p1.setCountries(c);
    p1.reinforce();

   Hand h;
    p1.setHand(h);
	p1.attack();
	p1.fortify();

    return 0;
}

