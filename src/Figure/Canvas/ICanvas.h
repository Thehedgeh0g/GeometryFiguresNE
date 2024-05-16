//
// Created by flipd on 20.04.2024.
//

#ifndef GEOMETRYFIGURES_ICANVAS_H
#define GEOMETRYFIGURES_ICANVAS_H


#include <cstdint>
#include <vector>
#include "../Shapes/CPoint.h"

class ICanvas
{
public:
    virtual void DrawLine(CPoint from, CPoint to, uint32_t lineColor) const = 0;

    virtual void FillPolygon(std::vector<CPoint> points, uint32_t fillColor) const = 0;

    virtual void DrawCircle(CPoint center, double radius, uint32_t lineColor) const = 0;

    virtual void FillCircle(CPoint center, double radius, uint32_t fillColor) const = 0;

    virtual ~ICanvas() = default;
};


#endif //GEOMETRYFIGURES_ICANVAS_H
