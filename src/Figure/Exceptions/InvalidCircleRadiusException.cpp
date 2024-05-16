//
// Created by flipd on 19.04.2024.
//

#include "InvalidCircleRadiusException.h"

const char *InvalidCircleRadiusException::what() const noexcept
{
    return "Radius must be positive.";
}
