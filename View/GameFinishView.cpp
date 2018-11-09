//
// Created by Yashar Dabiran on 2018-10-31.
//

#include <iostream>
#include <string>
#include "GameFinishView.h"

void GameFinishView::announceWinner(Player *winner) {
    std::cout << "Player Number " + to_string(winner->getId()) + " is the winner!" << std::endl;
}
