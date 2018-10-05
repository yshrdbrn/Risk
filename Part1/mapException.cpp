//
// Created by Yashar Dabiran on 2018-10-04.
//

#include "mapException.h"

const char *MapException::what() const {
    return message;
}
