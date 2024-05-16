//
// Created by flipd on 10.05.2024.
//

#include <iostream>
#include "ShapeController.h"

void ShapeController::ReadShapes()
{
    std::string line;
    while (std::getline(m_in, line))
    {
        if (line.empty())
        {
            break;
        }

        m_shapeService.ConstructShape(line);
    }
}

void ShapeController::PrintShapeWithMaxAreaInfo() const
{
    std::shared_ptr<IShape> shape = m_shapeService.GetShapeWithMaxArea();

    if (shape != nullptr)
    {
        m_out << "Shape with max area: " << shape->ToString() << std::endl;
    }
}

void ShapeController::PrintShapeWithMinPerimeterInfo() const
{
    std::shared_ptr<IShape> shape = m_shapeService.GetShapeWithMinPerimeter();

    if (shape != nullptr)
    {
        m_out << "Shape with min perimeter: " << shape->ToString() << std::endl;
    }
}

void ShapeController::RenderShapes()
{
    m_shapeService.RenderShapes();
}
