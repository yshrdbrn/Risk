#include "Player.h"
#include "../Part1/country.h"

int main()
{
    Country * c1;
    Country * c2 ;
    Country * c3 ;
    std::vector<Country*> c = {c1,c2, c3};
    Player p1;
    p1.setCountries(c);
   /* p1.reinforce();*/


   /* Hand h;
    p1.setHand(h);*/
    return 0;
}

