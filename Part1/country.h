//
// Created by Yashar Dabiran on 2018-10-04.
//

#ifndef RISKGAME_COUNTRY_H
#define RISKGAME_COUNTRY_H

#include <string>

class Country {
private:
    std::string name;

public:
    explicit Country(const std::string &name);

    const std::string &getName() const;

    bool operator==(const Country &other) const;

    bool operator!=(const Country &other) const;
};


#endif //RISKGAME_COUNTRY_H
