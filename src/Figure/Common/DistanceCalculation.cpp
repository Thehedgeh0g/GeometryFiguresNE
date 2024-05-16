//
// Created by flipd on 12.04.2024.
//

#include <valarray>
#include "DistanceCalculation.h"

double DistanceCalculation::CalculateDistance(CPoint startPoint, CPoint endPoint)
{
    double deltaX = endPoint.x - startPoint.x;
    double deltaY = endPoint.y - startPoint.y;
    return std::sqrt(deltaX * deltaX + deltaY * deltaY);
}
