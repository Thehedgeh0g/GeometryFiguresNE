//
// Created by flipd on 12.04.2024.
//

#include <valarray>
#include "CLineSegment.h"
#include "../Common/ConvertColor.h"
#include "../Exceptions/InvalidLineVertexCoordsException.h"
#include "../Common/ShapeToStringConverter.h"

CLineSegment::CLineSegment(
    const CPoint& startPoint,
    const CPoint& endPoint,
    const uint32_t& outlineColor
) :
    m_startPoint(startPoint),
    m_endPoint(endPoint),
    m_outlineColor(outlineColor)
{
    if (startPoint == endPoint)
    {
        throw InvalidLineVertexCoordsException();
    }
}

CLineSegment::~CLineSegment() = default;

const CPoint& CLineSegment::GetStartPoint() const
{
    return m_startPoint;
}

const CPoint& CLineSegment::GetEndPoint() const
{
    return m_endPoint;
}

std::uint32_t CLineSegment::GetOutlineColor() const
{
    return m_outlineColor;
}

double CLineSegment::GetArea() const
{
    return 0;
}

double CLineSegment::GetPerimeter() const
{
    double deltaX = m_endPoint.x - m_startPoint.x;
    double deltaY = m_endPoint.y - m_startPoint.y;
    return std::sqrt(deltaX * deltaX + deltaY * deltaY);
}

std::string CLineSegment::ToString() const
{
    return ShapeToStringConverter::ConvertToString(
        "rectangle",
        {m_startPoint, m_endPoint},
        {m_outlineColor},
        {}
    );
}

void CLineSegment::Draw(std::shared_ptr<ICanvas> canvas) const
{
    canvas->DrawLine(m_startPoint, m_endPoint, m_outlineColor);
}
