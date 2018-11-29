//
// Created by Yashar Dabiran on 2018-11-29.
//

#ifndef RISKGAME_SINGLEPLAYERGAMEENGINE_H
#define RISKGAME_SINGLEPLAYERGAMEENGINE_H

#include "GameEngine.h"

class SinglePlayerGameEngine: public GameEngine {
private:
    // Asks console if the user wants to change strategy
    void askIfWantToChangeStrategy(Player *player);

protected:
    void startUpPhase() override;

    void mainLoop() override;

    void initGame() override;

public:
    void startGame() override;

    ~SinglePlayerGameEngine() override = default;
};


#endif //RISKGAME_SINGLEPLAYERGAMEENGINE_H
