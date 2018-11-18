//
// Created by Yashar Dabiran on 2018-10-29.
//
#include "GameEngine.h"
#include "../View/GameSetupView.h"
#include "../View/GameFinishView.h"
#include "../Model/Map/riskException.h"
#include "./start_up_phase/startup.h"
#include "../Model/Player/HumanStrategy.h"
#include "../Model/Map/continent.h"
#include "../Model/Map/country.h"
#include "../View/PhaseView.h"
#include <chrono>
#include <algorithm>
#include "random"
#include <vector>
#include <iostream>
#include <string>



void GameEngine::startGame() {
    initGame();
    startUpPhase();
    mainLoop();
}

GameEngine::~GameEngine() {
    for (auto &player : players)
        delete player;
}

int GameEngine::getNumberOfPlayers() {
    return players.size();
}

int GameEngine::getNumberOfCardsInDeck() {
    return deck->getTotalCards();
}

int GameEngine::getNumberOfCountriesInMap() {
    return map->numberOfCountries();
}

void GameEngine::initGame() {
    MapLoader mapLoader;
    GameSetupView gameSetupView;
	PhaseView* phaseView = new PhaseView();
    std::vector<std::string> mapNames = mapLoader.getListOfAllMapFiles();

    // Check if the chosen map is valid
    while(true) {
        try {
            int mapNumber = gameSetupView.promptUserToChooseMapFile(mapNames);
            map = mapLoader.createMapWithFileName(mapNames[mapNumber]);
            break;
        } catch (RiskException &e) {
            gameSetupView.showError(e.what());
        }
    }

    // Create the Deck
    deck = new Deck(map->numberOfCountries());

    int numberOfPlayers = gameSetupView.promptUserToChooseNumberOfPlayers(MIN_PLAYERS, MAX_PLAYERS);

    for (int i = 0; i < numberOfPlayers; i++)
        players.push_back(new Player(i + 1, new HumanStrategy(), new Dice() , new Hand() , phaseView));
}

void GameEngine::startUpPhase() {

    auto temp = GameEngine::order_play(players);
    GameEngine::distributing_countries(map->getCountries(), temp);
    GameEngine::distributing_armies(temp);
    GameEngine::autoPlaceArmies(temp);
}

void GameEngine::mainLoop() {
    while(map->ownerOfAllCountries() == nullptr) {
        for(Player* &player: players) {
			/*PhaseState* ps = new PhaseState();
			PhaseView * view = new PhaseView(ps);
            ps->setPlayer(player);
            ps->setPhase("reinforcing");
            ps->setDescription(player->reinforce());
            ps->clear();
            ps->setPhase("attacking");
            ps->setDescription(player->attack());
			ps->clear();
            ps->setPhase("fortifying");
            ps->setDescription(player->fortify());
            ps->clear();*/
			player->startturn();
        }

    }

    GameFinishView gameFinishView;
    if (map->ownerOfAllCountries() != nullptr)
        gameFinishView.announceWinner(map->ownerOfAllCountries());
}

void GameEngine::setOwnershipOfCountriesToOnePlayer() {
    for(auto &country: map->getCountries()) {
        country->setOwner(players[0]);
    }
}

void GameEngine::setOwnershipOfCountriesToRandomPlayers() {
    std::vector<country_ptr> countries = map->getCountries();
    for (int i = 0; i < countries.size() - 1; i++)
        countries[i]->setOwner(players[0]);
    countries[countries.size() - 1]->setOwner(players[1]);
}

vector<Player*> GameEngine::order_play(vector <Player*> array) {              //method that takes in a vector of players
	unsigned seed = chrono::system_clock::now().time_since_epoch().count(); //and returns another vector of players with randomized positions

	shuffle(array.begin(), array.end(), std::default_random_engine(seed));

	return array;
	    
}

void GameEngine::distributing_countries(vector <country_ptr> array, vector<Player *> players) { // method that distributes countries to players
				
				unsigned seed = chrono::system_clock::now().time_since_epoch().count();  //setting the seed to system clock

				shuffle(array.begin(), array.end(), std::default_random_engine(seed));  //calling the shuffle method to randomize the 
				                                                                        //country array
				int a = 0;
				for (int i = 0; i < array.size();i++) {                        //distributing the countries to the players
					players[a]->addCountries(array[i]);                  //and setting the country's player to that player.
					array[i]->setOwner(players[a]);
					a++;
					if (a == players.size()) {
						a = 0;
					} 
				}

				
			}
//---------------------------------------------------------------------------------------------------------
			
 void GameEngine::distributing_armies(vector<Player*> players) {   //Distributing Armies method, looks at the numbe rof players
				                                                      //in the Vector of players, and distributes an amount of armies
				if (players.size() == 2) {                      //for all of them based on that
					for (int i = 0;i < players.size();i++) {
						
						players[i]->setArmies(40);            //if two players, each gets 40 armies
					}
				}
				
				else if (players.size() == 3) {
					for (int i = 0;i < players.size();i++) { //if 3 players, each gets 35 armies
						
						players[i]->setArmies(35);
					}
				}
				
				else if (players.size() == 4) {
					for (int i = 0;i < players.size();i++) {  // if 4 players, each gets 30 armies
						
						players[i]->setArmies(30);
					}
				}
				
				else if (players.size() == 5) {
					for (int i = 0;i < players.size();i++) {  //if 5 players, each gets 25 armies
						
						players[i]->setArmies(25);
					}
				}
				
				else if (players.size() == 6) {
					for (int i = 0;i < players.size();i++) {  //if 6 players, each gets 20 armies
						
						players[i]->setArmies(20);
					}
				}
			}

     void GameEngine:: placing_armies(vector<Player*> players) {  //Placing Armies method, prompts users to place their armies
	 int totalArmies;                                            //on their countries
	 int country;
	 
	 if (players.size()==2)              //the variable totalArmies if used as a delimiter for the for loop below
		 totalArmies = 40;
	 else if (players.size() == 3)
		 totalArmies = 35;
	 else if (players.size() == 4)
		 totalArmies = 30;
	 else if (players.size() == 5)
		 totalArmies = 25;
	 else if (players.size() == 6)
		 totalArmies = 20;


	 
	 for (int i = 0;i < totalArmies;i++) {  //the loop keeps going as long total armies is not 0
		 cout << endl;
		 
		 for (int a = 0;a < players.size();a++) {
			 if (players[a]->getCountries().size() == 0)
				 cout << players[a]->getName() << " you have no countries" << endl;  //If a player has no armies, he is skipped over
			 else {

				 cout << players[a]->getName()<<", you have "<<players[a]->getArmies()<<" armies and" <<
					 " your countries are : " << endl;           //informs the user of the amount of armies they have left and the countries
				                                                 //they own.
				 for (int c = 0;c < players[a]->getCountries().size();c++) {
					 cout << c << " " << players[a]->getCountries()[c]->getName() << " : " <<
						 players[a]->getCountries()[c]->getNumOfArmies() << " armies" << endl;
				 }

				 cout << "\nPlease enter the number of the country you would like to place an army on : ";
				 cin >> country;                                  //prompts the user to select one of his countries to place an army on

				 while (country > players[a]->getCountries().size() - 1 || country < 0) {
					 cout << "Invalid input, please try again: ";  //If the user enters non valid input (a country he does not own),
					 cin >> country;                               // error message is displayed until he enters a valid country
				 }
				 cout << endl;

				 players[a]->getCountries()[country]->incrementArmies(1); //increments the army on the country selected by 1
				 players[a]->removeArmies(1);                             //removes 1 army from the player

			 } 


		 }
	 }
 }

 void GameEngine::autoPlaceArmies(std::vector<Player*> players){
      int totalArmies;                                            //on their countries
	 int country;
	 
	 if (players.size()==2)              //the variable totalArmies if used as a delimiter for the for loop below
		 totalArmies = 40;
	 else if (players.size() == 3)
		 totalArmies = 35;
	 else if (players.size() == 4)
		 totalArmies = 30;
	 else if (players.size() == 5)
		 totalArmies = 25;
	 else if (players.size() == 6)
		 totalArmies = 20;

    for (int i = 0;i < totalArmies;i++){
        for (int a = 0;a < players.size();a++){
            for (int c = 0;c < players[a]->getCountries().size();c++){
                players[a]->getCountries()[c]->addNumOfArmies(1);

            }
        }   
    }
 }