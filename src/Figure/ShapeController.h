//
// Created by flipd on 10.05.2024.
//

#ifndef GEOMETRYFIGURES_SHAPECONTROLLER_H
#define GEOMETRYFIGURES_SHAPECONTROLLER_H


#include "Service/ShapeService.h"

class ShapeController
{
public:
    ShapeController(std::istream& in, std::ostream& out, ShapeService& shapeService)
        : m_in(in), m_out(out), m_shapeService(shapeService)
    {}

    void ReadShapes();

    void PrintShapeWithMaxAreaInfo() const;

    void PrintShapeWithMinPerimeterInfo() const;

    void RenderShapes();

private:
    ShapeService& m_shapeService;
    std::istream& m_in;
    std::ostream& m_out;
};


#endif //GEOMETRYFIGURES_SHAPECONTROLLER_H
