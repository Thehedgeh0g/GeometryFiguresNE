//
// Created by flipd on 12.04.2024.
//

#ifndef GEOMETRYFIGURES_SHAPEFACTORY_H
#define GEOMETRYFIGURES_SHAPEFACTORY_H


#include <unordered_map>
#include <string>
#include <memory>
#include <vector>
#include "../Shapes/CLineSegment.h"
#include "../Shapes/CCircle.h"
#include "../Shapes/CTriangle.h"
#include "../Shapes/CRectangle.h"
#include "../Shapes/FigureTypeEnum.h"

class ShapeFactory
{
public:
    static std::unique_ptr<IShape> CreateShape(std::string figureData);

private:
    static std::unordered_map<std::string, FigureTypeEnum> m_figureMap;

    static const std::string DATA_DELIMITER;

private:

    static CLineSegment CreateCLine(std::istringstream& iss);

    static CCircle CreateCCircle(std::istringstream& iss);

    static CTriangle CreateCTriangle(std::istringstream& iss);

    static CRectangle CreateCRectangle(std::istringstream& iss);
};


#endif //GEOMETRYFIGURES_SHAPEFACTORY_H
