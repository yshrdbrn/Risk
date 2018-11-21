//
// Created by Yashar Dabiran on 2018-11-20.
//

#include "State.h"

const map_ptr &State::getMap() const {
    return map;
}

void State::setMap(map_ptr map) {
    State::map = map;
}

const vector<Player *> &State::getPlayers() const {
    return players;
}

void State::setPlayers(vector<Player *> players) {
    State::players = players;
}

Deck *State::getDeck() const {
    return deck;
}

void State::setDeck(Deck *deck) {
    State::deck = deck;
}

State::~State() {
    for (auto &player : players)
        delete player;
}


/**
 * The function sets the phase state and notifies the observers
 * @param state new state of the phase
 */
void State::setPhaseState(std::string state) {
    phaseState = state;
    notify();
}

const string &State::getPhaseState() const {
    return phaseState;
}

void State::transferCountryOwnership(country_ptr country, Player *prevOwner, Player *newOwner) {
    prevOwner->removeCountry(country);
    newOwner->addCountry(country);
    country->setOwner(newOwner);
    calculateNewPercentage();
}

void State::calculateNewPercentage() {
    double totalCountries = map->numberOfCountries();

    dominationPercentage.clear();
    for (auto &player : players) {
        // Calculate the percentage owned by every player
        double playerPercentage = player->getCountries().size() * 100.0 / totalCountries;
        dominationPercentage.push_back((int)playerPercentage);
    }

    notify();
}

const vector<int> &State::getDominationPercentage() const {
    return dominationPercentage;
}
