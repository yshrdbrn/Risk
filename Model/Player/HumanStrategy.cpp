//
// Created by Yashar Dabiran on 2018-11-14.
//

#include "HumanStrategy.h"
#include "Player.h"
#include "../Map/continent.h"

void HumanStrategy::performAttack(std::vector<country_ptr> &countries, Hand &hand) {
    std::cout << "Player attacking phase.. " << endl ;
    bool isAttacking = true;
    string answer;
    country_ptr refAttCountry ;
    std::shared_ptr<Country>  refDefCountry;
    int numberOfDiceAtt;
    int numberOfDiceDef;

    //If the player chooses not to attack, it will exit the attack phase and move on to the next phase.
    while (isAttacking) {
        std::cout << "Do you want to attack?(yes/no)" << endl;
        cin >> answer;
        if (answer == "no") {
            isAttacking = false;
            break;
        }
        //Player chooses country to attack from and its neighbour to attack
        bool isValidAtt = false;
        do{
            string attCountry;
            std::cout << "Enter the name of the country you want to attack from" << endl;
            cin >> attCountry;
            //Check to see if country is owned by the player
            std::vector<shared_ptr<Country>> ::iterator iter;
            for (iter = countries.begin(); iter != countries.end(); iter++) {
                if ((*iter)->getName() == attCountry && (*iter)->getNumOfArmies() >= 2) {
                    isValidAtt = true;
                    refAttCountry = (*iter);
                    break;
                }
            }
            if(!isValidAtt)
                std::cout<< "Country is not a valid country to attack from" << endl;

        }while(!isValidAtt);
        std::vector<country_ptr> n = refAttCountry->getNeighbors();
        //country_ptr l = make_shared<Country>(*(n[1]));
        //Player chooses country to attack
        bool isValidDef = false;
        do{
            string defCountry;
            std::cout << "Enter the name of the country you want to attack" << endl;
            cin >> defCountry;
            //Check to see if countries are neighbours
            std::vector<shared_ptr<Country>> neighbors = refAttCountry->getNeighbors();
            std::vector<shared_ptr<Country>> ::iterator iter2;
            for (iter2= neighbors.begin(); iter2 != neighbors.end(); iter2++) {
                if ((*iter2)->getName() == defCountry && (*iter2)->getOwner()->getId() != refAttCountry->getOwner()->getId()) {
                    cout << "Attacking " << defCountry << "..." << endl;
                    refDefCountry = (*iter2);
                    isValidDef = true;
                    break;
                }
            }
            if (!isValidDef)
                std::cout<<"You can not attack " << defCountry<< "!" <<endl;
        }while(!isValidDef);

        //Checking if valid inoout for number of Dice
        bool isValidAttDice = false;
        std::cout << "Choose the number of dice you want to roll for ATTACK" << endl;
        cin >> numberOfDiceAtt;
        while((numberOfDiceAtt > 3 || numberOfDiceAtt < 1) || (numberOfDiceAtt > refAttCountry -> getNumOfArmies() - 1)) {
            std::cout << "Choose a valid number of Dice to roll. It must be between 1-3 and cannot be greater than the number of armies you have" << endl;
            cin >> numberOfDiceAtt;
        }
        bool isValidDefDice = false;
        std::cout << "Choose the number of Dice you want to roll for DEFENSE" << endl;
        cin >> numberOfDiceDef;
        while (!(numberOfDiceDef>=1 && numberOfDiceDef<=2 && numberOfDiceDef <= refDefCountry->getNumOfArmies())){
            std::cout << "Choose a valid number of Dice to roll. It must be between 1-2 and cannot be greater than the armies you have" << endl;
            cin >> numberOfDiceDef;
        }


        //Rolling dice for Attacker and Defender
        vector<int>  arrAtt;
        vector<int> arrDef;
        std::cout << "NOW ROLLING FOR ATTACKING COUNTRY " << endl;
        //cout << refAttCountry->getOwner()->getId() << "----------" << endl;
        arrAtt = refAttCountry->getOwner()->getDice()->diceRoll(numberOfDiceAtt);
        std::sort(arrAtt.begin(),arrAtt.end());
        std::cout << "NOW ROLLING FOR DEFENDING COUNTRY" << endl;
        arrDef = refDefCountry->getOwner()->getDice()->diceRoll(numberOfDiceDef);
        std::sort(arrDef.begin(), arrDef.end());
        //Comparing values to see who wins between Attacker and Defender and removing armies where appropiate
        std::cout << "Starting pair-wise comparison..." << endl;
        while (!arrAtt.empty() && !arrDef.empty()){
            //vector<int>::const_iterator maxAtt,maxDef;
            int maxAtt=arrAtt.back();
            cout<<"max dice for Player"<<refAttCountry->getOwner()->getId()<<" is "<<maxAtt<<endl;

            int maxDef = arrDef.back();
            cout<<"max dice for Player"<<refDefCountry->getOwner()->getId()<<" is "<<maxDef<<endl;
            if(maxAtt>maxDef){
                cout << refDefCountry->getName() << " lost one army!" <<endl;
                refDefCountry->removeNumOfArmies(1);

            }
            else{
                refAttCountry->removeNumOfArmies(1);
                cout<<refAttCountry->getName() << " lost one army" <<endl;
            }
            arrDef.pop_back();
            arrAtt.pop_back();
        }

        if(refDefCountry->getNumOfArmies() == 0){
            std::cout << "Player " << refAttCountry->getOwner()->getId() << " won the battle" << endl;
            std::cout << refDefCountry->getName() << " has no more armies on it!" << endl;
            refDefCountry->setOwner(refAttCountry->getOwner());
            std::cout << refDefCountry->getName() << " now belongs to Player" << refAttCountry->getOwner()->getId() << "!" << endl;
            int armiesToMove;
            //Validate the number of armies to move
            bool isValidNumber=false;
            do{
                std::cout << "How many armies would you like to move to "<< refDefCountry->getName() << " ?" <<endl;
                std::cin >> armiesToMove;
                if(armiesToMove>=1 && armiesToMove <= refAttCountry->getNumOfArmies()-1){
                    isValidNumber=true;
                }
                else std::cout << "You can not move this amout of armies" << endl;
            }while(!isValidNumber);

        }
        if(refAttCountry->getNumOfArmies() == 0){
            std::cout << "Player " << refDefCountry->getOwner()->getId() << " won the battle" << endl;
            refAttCountry->setOwner(refDefCountry->getOwner());
            int armiesToMove;
            bool isValidNumber=false;
            do{
                //Asking the winner to Move Armies to new territory
                std::cout << "How many armies would you like to move to "<< refDefCountry->getName() << " ?" <<endl;
                std::cin >> armiesToMove;
                if(armiesToMove>=1 && armiesToMove <= refDefCountry->getNumOfArmies()-1){
                    isValidNumber=true;
                }
                else std::cout << armiesToMove<< " is not a valid number of armies" << endl;
            }while(!isValidNumber);

        }


    }
    std::cout<<"Exiting attack phase..." <<endl;
}

void HumanStrategy::performFortify(std::vector<country_ptr> &countries, Hand &hand) {
    std::cout << "Beginning Fortify Phase... " << endl;
    bool isFortifying = true;
    std::string answer;
    country_ptr refSourceCountry;
    std::shared_ptr<Country> refTargetCountry;
    string sourceCountry;
    int armiesToMove;
    std::string targetCountry;
    while (isFortifying) {
        std::cout << "Do you want to move armies on the map?(yes/no)" << endl;
        cin >> answer;
        if (answer == "no") {
            isFortifying = false;
            break;
        }
        //Player chooses country to attack from and its neighbour to attack
        bool isValidSource = false;
        do{
            std::cout << "Enter the name of the country you want to move armies from" << endl;
            cin >> sourceCountry;
            //Check to see if country is owned by the player
            std::vector<country_ptr> ::iterator iter;
            for (iter = countries.begin(); iter != countries.end(); iter++) {
                if ((*iter)->getName() == sourceCountry) {
                    isValidSource = true;
                    refSourceCountry = (*iter);
                    break;
                }
            }
            if(!isValidSource)
                cout<< "Can't move armies from" << sourceCountry << "! Please make sure you own the country!" <<endl;

        }while(!isValidSource);

        bool isValidNumber=false;
        do{
            std::cout << "Enter the number of armies you wnat to move from:" << sourceCountry << endl;
            std::cin >> armiesToMove;
            if(armiesToMove>=1 && armiesToMove <= refSourceCountry->getNumOfArmies()-1){
                isValidNumber=true;
            }
            else std::cout << armiesToMove<< " is not a valid number of armies. Please make sure you have enough armies to go through with the move!" << endl;
        }while(!isValidNumber);

        //Player chooses target country
        bool isValidTarget = false;
        do{
            std::cout << "Enter the name of the target country:" << endl;
            cin >> targetCountry;
            //Check to see if countries are neighbours
            std::vector<shared_ptr<Country>> neighbors = refSourceCountry->getNeighbors();
            std::vector<shared_ptr<Country>> ::iterator iter2;
            for (iter2= neighbors.begin(); iter2 != neighbors.end(); iter2++) {
                if ((*iter2)->getName() == targetCountry && (*iter2)->getOwner() == refSourceCountry->getOwner()) {
                    refTargetCountry = (*iter2);
                    isValidTarget = true;
                    break;
                }
            }
            if (!isValidTarget)
                std::cout<< targetCountry << " is not a valid taget country! Please make sure that the target country is neighboring to the source country and are both owned by you!" << endl;

        }while(!isValidTarget);

        std::cout<< "proceeding to move " << armiesToMove << " armies from " << sourceCountry << " to " << targetCountry << endl;
        refTargetCountry->addNumOfArmies(armiesToMove);
        refSourceCountry->removeNumOfArmies(armiesToMove);
    }
    std::cout << refTargetCountry->getName() << " now has " << refTargetCountry->getNumOfArmies() << " armies." << endl;
    std::cout << refSourceCountry->getName() << " now has " << refSourceCountry->getNumOfArmies() << " armies." << endl;
}

void HumanStrategy::performReinforce(std::vector<country_ptr> &countries, Hand &hand, Player *player) {
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

    //Prompt Player to exchange cards for extra armies
    hand.exchange(armies);

    while(armies > 0){
        cout<< "You have " << armies << " armies to place " << endl;
        int armiesToPlace;
        std::string country_input;
        //prompt user tp select the number pf armies to place and check if they have enough armies
        cout << "please enter the number of armies you wish to place " << endl ;
        cin >> armiesToPlace ;
        if(armiesToPlace > armies){
            cout << "You don't have enough armies to place" << endl;
            continue;
        }
        else{
            bool countryIsOwned = false;
            do{
                cout << "Please enter the name of the country where you wish to place your armies: " << endl;
                cin >> country_input ;
                //iterate through "countries" vector to check if country is owned by the player
                std::vector<country_ptr> :: iterator iter;
                for(iter=countries.begin() ; iter!=countries.end() ; iter++){
                    if((*iter)->getName() == country_input){
                        countryIsOwned=true;
                        (*iter)->addNumOfArmies(armiesToPlace);
                        armies = armies - armiesToPlace;
                        continue;
                    }
                }
                if(countryIsOwned){
                    cout << "Placed " << armiesToPlace << " armies on " << country_input << "." <<endl;
                }
                else{
                    cout << "Country name in not valid..." << endl;
                    continue;
                }
            } while(!countryIsOwned);
            std::cout<<"You have no more armies to place! Ending reinforcement phase..."<<endl;

        }
    }
}
