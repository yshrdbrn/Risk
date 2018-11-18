#pragma once
#include <string>
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
    virtual void update(std::string) = 0;

};


