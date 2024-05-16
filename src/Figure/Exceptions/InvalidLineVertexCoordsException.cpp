//
// Created by flipd on 19.04.2024.
//

#include "InvalidLineVertexCoordsException.h"

const char *InvalidLineVertexCoordsException::what() const noexcept
{
    return "Start and end points must be different.";
}
