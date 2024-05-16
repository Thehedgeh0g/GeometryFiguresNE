//
// Created by flipd on 19.04.2024.
//

#include "InvalidTriangleVertexCoords.h"

const char *InvalidTriangleVertexCoords::what() const noexcept
{
    return "Coordinates of the vertices of the triangle cannot coincide";
}
