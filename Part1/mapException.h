//
// Created by Yashar Dabiran on 2018-10-04.
//

#ifndef RISKGAME_MAPEXCEPTION_H
#define RISKGAME_MAPEXCEPTION_H

#include <exception>
#include <string>

class MapException: public std::exception {
private:
    const char *message;
public:
    explicit MapException(const char *msg): message(msg) {};

    const char *what() const override;
};


#endif //RISKGAME_MAPEXCEPTION_H
