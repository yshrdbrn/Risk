#pragma once
class GameState;
/**
 * Interface for the Observer
 */
class Observer {

public:

    /**
     * Update the state of this observer
     * 
     * 
     */
    virtual void update(GameState*) = 0;

};


