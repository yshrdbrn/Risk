//
// Created by Yashar Dabiran on 2018-10-04.
//

#include "country.h"

Country::Country(const std::string &name) : name(name) {}

bool Country::operator==(const Country &other) const {
    return name == other.name;
}

bool Country::operator!=(const Country &other) const {
    return !(other == *this);
}

const std::string &Country::getName() const {
    return name;
}
