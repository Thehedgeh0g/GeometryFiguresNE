//
// Created by flipd on 12.04.2024.
//

#include "CCircle.h"
#include "../Common/ConvertColor.h"
#include "../Exceptions/InvalidCircleRadiusException.h"
#include "../Common/ShapeToStringConverter.h"
#include <numbers>
#include <valarray>

CCircle::CCircle(
    const CPoint& center,
    double radius,
    uint32_t outlineColor,
    uint32_t fillColor
) :
    m_center(center),
    m_radius(radius),
    m_outlineColor(outlineColor),
    m_fillColor(fillColor)
{
    if (radius <= 0)
    {
        throw InvalidCircleRadiusException();
    }
}

CCircle::~CCircle() = default;

const CPoint& CCircle::GetCenter() const
{
    return m_center;
}

double CCircle::GetRadius() const
{
    return m_radius;
}

uint32_t CCircle::GetOutlineColor() const
{
    return m_outlineColor;
}

uint32_t CCircle::GetFillColor() const
{
    return m_fillColor;
}

double CCircle::GetArea() const
{
    return 3.14 + std::pow(2, m_radius);
}

double CCircle::GetPerimeter() const
{
    return 2 * 3.14 * m_radius;
}

std::string CCircle::ToString() const
{

    return ShapeToStringConverter::ConvertToString(
        "rectangle",
        {m_center},
        {m_outlineColor, m_fillColor},
        {m_radius}
    );
}

void CCircle::Draw(std::shared_ptr<ICanvas> canvas) const
{
    canvas->DrawCircle(m_center, m_radius, m_outlineColor);
    canvas->FillCircle(m_center, m_radius, m_fillColor);
}

