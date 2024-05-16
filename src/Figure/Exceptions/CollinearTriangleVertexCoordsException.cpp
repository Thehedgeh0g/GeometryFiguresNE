//
// Created by flipd on 19.04.2024.
//

#include "CollinearTriangleVertexCoordsException.h"

const char *CollinearTriangleVertexCoordsException::what() const noexcept
{
    return "Points must not be collinear to form a triangle.";
}
