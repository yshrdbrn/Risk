//
// Created by Yashar Dabiran on 2018-11-20.
//

#ifndef RISKGAME_STATE_H
#define RISKGAME_STATE_H

#include <vector>
#include <string>
#include "Observable.h"
#include "../Model/Maploader/mapLoader.h"
#include "../Model/Player/Player.h"
#include "../Model/Cards/Deck.h"

class State: public Observable {
private:
    map_ptr map;
    std::vector<Player *> players;
    Deck *deck;

    // State of the phase is kept in here
    std::string phaseState;
    // a vector showing the percentage of map owned by each player
    std::vector<int> dominationPercentage;

public:
    ~State();

    //// Getters and Setters
    const map_ptr &getMap() const;

    void setMap(map_ptr map);

    const vector<Player *> &getPlayers() const;

    void setPlayers(vector<Player *> players);

    Deck *getDeck() const;

    void setDeck(Deck *deck);


    //// State Change Methods
    void setPhaseState(std::string state);

    void addToPhaseState(std::string state);

    void finishCurrentState();

    const string &getPhaseState() const;

    /**
     * Changes the owner of the country from one to another and calls calculateNewPercentage()
     * @param country the country to change the owner of
     * @param prevOwner the previous owner of the country
     * @param newOwner  the new owner of the country
     */
    void transferCountryOwnership(country_ptr country, Player *prevOwner, Player *newOwner);

    const vector<int> &getDominationPercentage() const;


    //// Helper methods

    /**
     * Calculates percentage of the map every player owns and notifies the observers
     */
    void calculateNewPercentage();
};


#endif //RISKGAME_STATE_H
