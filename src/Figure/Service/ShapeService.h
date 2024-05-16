//
// Created by flipd on 10.05.2024.
//

#ifndef GEOMETRYFIGURES_SHAPESERVICE_H
#define GEOMETRYFIGURES_SHAPESERVICE_H


#include <string>
#include <memory>
#include <vector>
#include "../Shapes/IShape.h"
#include "../Canvas/CCanvas.h"

class ShapeService
{
public:
    void ConstructShape(const std::string& line);

    [[nodiscard]] std::shared_ptr<IShape> GetShapeWithMaxArea() const;

    [[nodiscard]] std::shared_ptr<IShape> GetShapeWithMinPerimeter() const;

    void RenderShapes();

private:
    const unsigned WIDTH_WINDOW = 1920;
    const unsigned HEIGHT_WINDOW = 1080;
    const std::string TITLE_WINDOW = "Window";

    std::vector<std::shared_ptr<IShape>> m_shapes = {};
    std::shared_ptr<CCanvas> m_canvas;
};


#endif //GEOMETRYFIGURES_SHAPESERVICE_H
