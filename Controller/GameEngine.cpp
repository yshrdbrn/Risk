//
// Created by Yashar Dabiran on 2018-10-29.
//

#include <vector>
#include <iostream>
#include <string>
#include "GameEngine.h"
#include "../View/GameSetupView.h"
#include "../View/GameFinishView.h"
#include "../Model/Map/riskException.h"
#include "./start_up_phase/startup.h"
#include "../Model/Player/HumanStrategy.h"
#include "../Model/Player/AggressiveComputerStrategy.h"
#include "../Model/Player/BenevolentComputerStrategy.h"
#include "../Model/Player/RandomComputerStrategy.h"
#include "../Model/Player/CheaterComputerStrategy.h"
#include "../View/PhaseObserver.h"
#include "../View/StatisticsObserver.h"

bool GameEngine::playerDoesNotOwnAnyCountries(Player *player) {
    return player->getCountries().empty();
}

void GameEngine::startUpPhase() {

    auto temp = startup::order_play(state.getPlayers());

    startup::distributing_countries(state.getMap()->getCountries(), temp);
    startup::distributing_armies(temp);
    startup::placing_armies(temp);
}