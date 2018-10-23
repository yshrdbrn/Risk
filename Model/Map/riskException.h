//
// Created by Yashar Dabiran on 2018-10-10.
//

#ifndef RISKGAME_RISKEXCEPTION_H
#define RISKGAME_RISKEXCEPTION_H

#include <exception>

class RiskException: public std::exception {
private:
    const char *message;
public:
    explicit RiskException(const char *msg): message(msg) {};

    const char *what() const noexcept override;
};


#endif //RISKGAME_RISKEXCEPTION_H
