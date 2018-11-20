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

    std::string phaseState;

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

    const string &getPhaseState() const;
};


#endif //RISKGAME_STATE_H
