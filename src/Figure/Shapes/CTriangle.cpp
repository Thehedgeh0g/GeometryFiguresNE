//
// Created by flipd on 12.04.2024.
//

#include "CTriangle.h"
#include "../Common/DistanceCalculation.h"
#include "../Common/ConvertColor.h"
#include "../Exceptions/CollinearTriangleVertexCoordsException.h"
#include "../Exceptions/InvalidTriangleVertexCoords.h"
#include "../Common/ShapeToStringConverter.h"

CTriangle::CTriangle(
    CPoint vertex1,
    CPoint vertex2,
    CPoint vertex3,
    uint32_t outlineColor,
    uint32_t fillColor
) :
    m_vertex1(vertex1),
    m_vertex2(vertex2),
    m_vertex3(vertex3),
    m_outlineColor(outlineColor),
    m_fillColor(fillColor)
{
    if (vertex1 == vertex2 || vertex1 == vertex3 || vertex2 == vertex3)
    {
        throw InvalidTriangleVertexCoords();
    }

    double crossProduct = (vertex2.x - vertex1.x) * (vertex3.y - vertex1.y) -
                          (vertex3.x - vertex1.x) * (vertex2.y - vertex1.y);
    if (crossProduct == 0)
    {
        throw CollinearTriangleVertexCoordsException();
    }
}

CTriangle::~CTriangle() = default;

uint32_t CTriangle::GetOutlineColor() const
{
    return m_outlineColor;
}

uint32_t CTriangle::GetFillColor() const
{
    return m_fillColor;
}

CPoint CTriangle::GetVertex1()
{
    return m_vertex1;
}

CPoint CTriangle::GetVertex2()
{
    return m_vertex2;
}

CPoint CTriangle::GetVertex3()
{
    return m_vertex3;
}

double CTriangle::GetArea() const
{
    return 0.5 * std::abs(
        m_vertex1.x * (m_vertex2.y - m_vertex3.y) +
        m_vertex2.x * (m_vertex3.y - m_vertex1.y) +
        m_vertex3.x * (m_vertex1.y - m_vertex2.y)
    );
}

double CTriangle::GetPerimeter() const
{
    double edge1 = DistanceCalculation::CalculateDistance(m_vertex1, m_vertex2);
    double edge2 = DistanceCalculation::CalculateDistance(m_vertex2, m_vertex3);
    double edge3 = DistanceCalculation::CalculateDistance(m_vertex3, m_vertex1);
    return edge1 + edge2 + edge3;
}

std::string CTriangle::ToString() const
{
    return ShapeToStringConverter::ConvertToString(
        "triangle",
        {m_vertex1, m_vertex2, m_vertex3},
        {m_outlineColor, m_fillColor},
        {}
    );
}

void CTriangle::Draw(std::shared_ptr<ICanvas> canvas) const
{
    canvas->DrawLine(m_vertex1, m_vertex2, m_outlineColor);
    canvas->DrawLine(m_vertex2, m_vertex3, m_outlineColor);
    canvas->DrawLine(m_vertex3, m_vertex1, m_outlineColor);

    canvas->FillPolygon({m_vertex1, m_vertex2, m_vertex3}, m_fillColor);
}
