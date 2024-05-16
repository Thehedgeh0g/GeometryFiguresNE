//
// Created by flipd on 12.04.2024.
//

#include <stdexcept>
#include "CRectangle.h"
#include "../Common/DistanceCalculation.h"
#include "../Common/ConvertColor.h"
#include "../Exceptions/InvalidRectangleWidthHeightException.h"
#include "../Common/ShapeToStringConverter.h"

CRectangle::CRectangle(CPoint leftBottomVertex, double height, double width, uint32_t outlineColor,
                       uint32_t fillColor) :
    m_height(height),
    m_width(width),
    m_leftBottomVertex(leftBottomVertex),
    m_outlineColor(outlineColor),
    m_fillColor(fillColor)
{
    if (height <= 0 || width <= 0)
    {
        throw InvalidRectangleWidthHeightException();
    }
}

CRectangle::~CRectangle() = default;


const CPoint& CRectangle::GetLeftBottomVertex() const
{
    return m_leftBottomVertex;
}

uint32_t CRectangle::GetOutlineColor() const
{
    return m_outlineColor;
}

uint32_t CRectangle::GetFillColor() const
{
    return m_fillColor;
}

double CRectangle::GetArea() const
{
    return m_width * m_height;
}

double CRectangle::GetPerimeter() const
{
    return 2 * (m_width + m_height);
}

std::string CRectangle::ToString() const
{
    return ShapeToStringConverter::ConvertToString(
        "rectangle",
        {m_leftBottomVertex},
        {m_outlineColor, m_fillColor},
        {m_width, m_height}
    );
}

void CRectangle::Draw(std::shared_ptr<ICanvas> canvas) const
{
    CPoint rightBottomPoint(m_leftBottomVertex.x + m_width, m_leftBottomVertex.y);
    CPoint rightTopPoint(rightBottomPoint.x, rightBottomPoint.y + m_width);
    CPoint leftTopPoint(rightTopPoint.x - m_width, rightTopPoint.y);

    canvas->DrawLine(m_leftBottomVertex, rightBottomPoint, m_outlineColor);
    canvas->DrawLine(rightBottomPoint, rightTopPoint, m_outlineColor);
    canvas->DrawLine(rightTopPoint, leftTopPoint, m_outlineColor);
    canvas->DrawLine(leftTopPoint, m_leftBottomVertex, m_outlineColor);

    canvas->FillPolygon({m_leftBottomVertex, rightBottomPoint, rightTopPoint, leftTopPoint}, m_fillColor);
}

