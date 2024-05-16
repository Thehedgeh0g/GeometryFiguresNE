//
// Created by flipd on 12.04.2024.
//

#include "ShapeFactory.h"
#include "../Common/ConvertColor.h"
#include <stdexcept>
#include <sstream>
#include "../Exceptions/InvalidRectangleWidthHeightException.h"
#include "../Exceptions/InvalidLineVertexCoordsException.h"
#include "../Exceptions/InvalidCircleRadiusException.h"
#include "../Exceptions/CollinearTriangleVertexCoordsException.h"
#include "../Exceptions/InvalidTriangleVertexCoords.h"

const std::string ShapeFactory::DATA_DELIMITER = " ";

std::unordered_map<std::string, FigureTypeEnum> ShapeFactory::m_figureMap = {
    {"line",      FigureTypeEnum::CLine},
    {"rectangle", FigureTypeEnum::CRectangle},
    {"triangle",  FigureTypeEnum::CTriangle},
    {"circle",    FigureTypeEnum::CCircle},
};

std::unique_ptr<IShape> ShapeFactory::CreateShape(std::string figureData)
{
    size_t pos;
    std::istringstream iss(figureData);
    std::string shapeName;
    iss >> shapeName;

    auto it = m_figureMap.find(shapeName);
    if (it != m_figureMap.end())
    {
        switch (it->second)
        {
            case FigureTypeEnum::CCircle:
                return std::make_unique<CCircle>(CreateCCircle(iss));
            case FigureTypeEnum::CRectangle:
                return std::make_unique<CRectangle>(CreateCRectangle(iss));
            case FigureTypeEnum::CTriangle:
                return std::make_unique<CTriangle>(CreateCTriangle(iss));
            case FigureTypeEnum::CLine:
                return std::make_unique<CLineSegment>(CreateCLine(iss));
            default:
                throw std::invalid_argument("invalid figure data format");
        }
    }
}

CLineSegment ShapeFactory::CreateCLine(std::istringstream& iss)
{
    try
    {
        double startX, startY, endX, endY;

        if (!(iss >> startX >> endX >> startY >> endY))
        {
            throw std::invalid_argument("Invalid line segment coordinates");
        }

        uint32_t outlineColor;
        if (!(iss >> std::hex >> outlineColor))
        {
            throw std::invalid_argument("Invalid color values");
        }

        return {{startX, startY}, {endX, endY}, outlineColor};
    }
    catch (const InvalidLineVertexCoordsException& err)
    {
        throw err;
    }
    catch (...)
    {
        throw std::invalid_argument("invalid Line Data");
    }
}

CCircle ShapeFactory::CreateCCircle(std::istringstream& iss)
{
    try
    {
        double centerX, centerY, radius;

        if (!(iss >> centerX >> centerY >> radius))
        {
            throw std::invalid_argument("Invalid line segment coordinates");
        }

        uint32_t outlineColor, fillColor;
        if (!(iss >> std::hex >> outlineColor >> fillColor))
        {
            throw std::invalid_argument("Invalid color values");
        }
        return {{centerX, centerY}, radius, outlineColor, fillColor};
    }
    catch (const InvalidCircleRadiusException& err)
    {
        throw err;
    }
    catch (const std::invalid_argument&)
    {
        throw std::invalid_argument("invalid Circle Data");
    }
}

CTriangle ShapeFactory::CreateCTriangle(std::istringstream& iss)
{
    try
    {
        double vertex1X, vertex1Y, vertex2X, vertex2Y, vertex3X, vertex3Y;

        if (!(iss >> vertex1X >> vertex1Y >> vertex2X >> vertex2Y >> vertex3X >> vertex3Y))
        {
            throw std::invalid_argument("Invalid triangle coordinates");
        }

        uint32_t outlineColor, fillColor;
        if (!(iss >> std::hex >> outlineColor >> fillColor))
        {
            throw std::invalid_argument("Invalid color values");
        }
        return {
            {vertex1X, vertex1Y},
            {vertex2X, vertex2Y},
            {vertex3X, vertex3Y},
            outlineColor,
            fillColor};
    }
    catch (const CollinearTriangleVertexCoordsException& err)
    {
        throw err;
    }
    catch (const InvalidTriangleVertexCoords& err)
    {
        throw err;
    }
    catch (...)
    {
        throw std::invalid_argument("invalid Triangle Data");
    }
}

CRectangle ShapeFactory::CreateCRectangle(std::istringstream& iss)
{
    try
    {
        double leftTopX, leftTopY, height, width;

        if (!(iss >> leftTopX >> leftTopY >> height >> width)){
            throw std::invalid_argument("Invalid triangle coordinates");
        }

        uint32_t outlineColor, fillColor;
        if (!(iss >> std::hex >> outlineColor >> fillColor))
        {
            throw std::invalid_argument("Invalid color values");
        }
        return {
            {leftTopX, leftTopY},
            height,
            width,
            outlineColor,
            fillColor
        };
    }
    catch (const InvalidRectangleWidthHeightException& err)
    {
        throw err;
    }
    catch (...)
    {
        throw std::invalid_argument("invalid Rectangle Data");
    }
}


