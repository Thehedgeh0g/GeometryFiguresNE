//
// Created by flipd on 12.04.2024.
//

#include "CPoint.h"

CPoint::CPoint(double x, double y) : x(x), y(y)
{}

bool CPoint::operator==(CPoint other) const
{
    return x == other.x && y == other.y;
}

bool CPoint::operator!=(CPoint other) const
{
    return !(*this == other);
}