//
// Created by Yashar Dabiran on 2018-10-10.
//

#include "riskException.h"

const char *RiskException::what() const noexcept {
    return message;
}
