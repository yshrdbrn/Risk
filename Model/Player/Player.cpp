#include <algorithm>
#include "Player.h"
#include <string>
#include <map>
#include <exception>




Player::Player(){};

Player::Player(int playerID) : id(playerID){}

Hand Player::getHand(){
    return hand ; 
}

void Player::setHand(Hand &h){
    hand = h;
}

Dice * Player::getDice(){
    return dice;
}

void Player::setDice(Dice * d){
    dice = d;
}

std::vector<Country *> Player::getCountries(){
    return countries;
}

void Player::setCountries(std::vector<Country*>& c){
    countries = c;
}

void Player::setContinents(std::vector<Continent*>& c){
    continents = c;
}

std::vector<Continent*> Player::getContinents(){
    return continents;
}

int Player::getId() const {
    return id;
}

void Player::setId(int id) {
    Player::id = id;
}


void Player::attack(){
    std::cout << "Player attacking phase.. " << endl ;
	bool isAttacking = true;
	string answer;
    Country * refAttCountry ; 
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
		std::vector<Country*> ::iterator iter;
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
			if ((*iter2)->getName() == defCountry && (*iter2)->getOwner() != refAttCountry->getOwner()) {
                refDefCountry = (*iter2);
            	isValidDef = true;
				break;
			}
		}
        if (!isValidDef)  
            std::cout << "Not a neighboring country" << endl;
        }while(!isValidDef);


        bool isValid = false;
        do {
			std::cout << "Choose the number of dice you want to roll for ATTACK" << endl;
			cin >> numberOfDiceAtt;
			while(numberOfDiceAtt > 3 || numberOfDiceAtt < 1 && numberOfDiceAtt <= refAttCountry -> getNumOfArmies() - 1) {
				std::cout << "Choose a valid number of Dice to roll. It must be between 1-3 and cannot be greater than the number of armies you have" << endl;
				cin >> numberOfDiceAtt;
			}
			std::cout << "Choose the number of Dice you want to roll for DEFENSE" << endl;
			cin >> numberOfDiceDef;
				while (numberOfDiceDef > 2 || numberOfDiceDef < 1 && numberOfDiceDef <= refDefCountry->getNumOfArmies()) {
					std::cout << "Choose a valid number of Dice to roll. It must be between 1-2 and cannot be greater than the armies you have" << endl;
					cin >> numberOfDiceDef;
				}
		

        }while(!isValid);

            vector<int>  arrAtt;
		    vector<int> arrDef;
		    std::cout << "NOW ROLLING FOR ATTACKING COUNTRY " << endl;
			arrAtt = refAttCountry->getOwner()->getDice()->diceRoll(numberOfDiceAtt);
			std::sort(arrAtt.begin(),arrAtt.end());
			std::cout << "NOW ROLLING FOR DEFENDING COUNTRY" << endl;
			arrDef = refDefCountry->getOwner()->getDice()->diceRoll(numberOfDiceDef);
			//std::sort(arrDef.begin(), arrDef.end());
			
			while (arrAtt.size() != 0 || arrDef.size() != 0){
                vector<int>::const_iterator maxAtt,maxDef;  
                maxAtt = std::max_element(arrAtt.begin(), arrAtt.end());
                maxDef =  std::max_element(arrDef.begin(), arrDef.end());
				if(*maxAtt>*maxDef){
					refDefCountry->removeNumOfArmies(1);
				}
                else{
                    refAttCountry->removeNumOfArmies(1);
                }
                arrAtt.erase(maxAtt);
                arrDef.erase(maxDef);	
			}    

            if(refDefCountry->getNumOfArmies() == 0){
                std::cout << "Player " << refAttCountry->getOwner()->getId() << " won the battle" << endl;
                refDefCountry->setOwner(refAttCountry->getOwner());
                 int armiesToMove;
                //Asking the winner to Move Armies to new territory
                std::cout << "How many armies would you like to move to "<< refDefCountry->getName() << " ?" <<endl;
                cin  >> armiesToMove;
                //Validate the number of armies
                bool isValidNumber=false;
                do{
                    std::cout << "Enter the number of countries you want to move:" << endl;
                    std::cin >> armiesToMove;
                    if(armiesToMove>=1 && armiesToMove <= refAttCountry->getNumOfArmies()-1){
                    isValidNumber=true;
                    }
                    else std::cout << armiesToMove<< " is not a valid number of countries" << endl;
                }while(!isValidNumber);

            }
            if(refAttCountry->getNumOfArmies() == 0){}
                std::cout << "Player " << refDefCountry->getOwner()->getId() << " won the battle" << endl;
                refAttCountry->setOwner(refDefCountry->getOwner());
                int armiesToMove;
                //Asking the winner to Move Armies to new territory
                std::cout << "How many armies would you like to move to "<< refDefCountry->getName() << " ?" <<endl;
                cin  >> armiesToMove;
                //Validate the number of armies
                bool isValidNumber=false;
                do{
                    std::cout << "Enter the number of countries you want to move:" << endl;
                    std::cin >> armiesToMove;
                    if(armiesToMove>=1 && armiesToMove <= refDefCountry->getNumOfArmies()-1){
                    isValidNumber=true;
                    }
                    else std::cout << armiesToMove<< " is not a valid number of countries" << endl;
                }while(!isValidNumber);

            }
            

		}






void Player::fortify(){
    std::cout << "Beginning Fortify Phase... " << endl;
        bool isFortifying = true;
        std::string answer;
        Country * refSourceCountry;
        std::shared_ptr<Country> refTargetCountry;
        string sourceCountry;
         int armiesToMove;
        std::string targetCountry;
    while (isFortifying) {
		std::cout << "Do you want to move countries on the map?(yes/no)" << endl;
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
		std::vector<Country*> ::iterator iter;
		for (iter = countries.begin(); iter != countries.end(); iter++) {
			if ((*iter)->getName() == sourceCountry) {
				isValidSource = true;
				refSourceCountry = (*iter);
				break;
			}            
		}
        if(!isValidSource)
            cout<< "Country is not a valid country to attack from" << endl;

        }while(!isValidSource);

        bool isValidNumber=false;
        do{
            std::cout << "Enter the number of countries you wnat to move:" << endl;
            std::cin >> armiesToMove;
            if(armiesToMove>=1 && armiesToMove <= refSourceCountry->getNumOfArmies()-1){
                isValidNumber=true;
            }
            else std::cout << armiesToMove<< " is not a valid number of countries" << endl;
        }while(!isValidNumber);

	//Player chooses target country
    bool isValidTarget = false;
        do{
		cout << "Enter the name of the target country" << endl;
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
            cout<< targetCountry << "is not a valid taget country!" << endl;

        }while(!isValidTarget);
		
        cout<< "proceeding to move " << armiesToMove << " from " << sourceCountry << " to " << targetCountry << endl;
        refTargetCountry->addNumOfArmies(armiesToMove);
        refSourceCountry->removeNumOfArmies(armiesToMove);
    }
}

    




//Reinforce method
void Player:: reinforce(){
    std::cout << "begin reinforcing phase... " << endl;
        //number of armies is initially 3
        int armies = 3 ;

        //add number of armies based on number of countries owned
        if(countries.size()/3 > 3){
            armies = armies + (countries.size()/3-3);
        }

        //Map Continent names to int for "switch case"
        std::map<std::string, int > stringToIntMap ;

        //Initialize HashMap 
        stringToIntMap["Asia"]= 1;
        stringToIntMap["North America"] = 2;
        stringToIntMap["Europe"] = 3;
        stringToIntMap["Africa"] = 4;
        stringToIntMap["South America"]= 5;
        stringToIntMap["Australia"] = 6;

        //Give Player extra armies if they own a continent
        if(continents.size() != 0) {
            for (int i = 0; i < continents.size(); i++) {
                switch (stringToIntMap[continents[i]->getName()]) {
                    case (1) :
                        armies = armies + 7;
                        break;
                    case (2) :
                        armies = armies + 5;
                        break;
                    case (3) :
                        armies = armies + 4;
                        break;
                    case (4) :
                        armies = armies + 3;
                        break;
                    case (5) :
                        armies = armies + 2;
                        break;
                    case (6) :
                        armies = armies + 2;
                        break;
                }
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
                    std::vector<Country*> :: iterator iter;
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

            }
            }
}
