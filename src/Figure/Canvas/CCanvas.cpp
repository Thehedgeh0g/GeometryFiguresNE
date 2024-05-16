//
// Created by flipd on 21.04.2024.
//

#include "CCanvas.h"
#include <SFML/Graphics.hpp>

void CCanvas::DrawLine(CPoint from, CPoint to, uint32_t lineColor) const
{
    sf::VertexArray line(sf::PrimitiveType::Lines, 2);
    line[0].position = sf::Vector2f(from.x, from.y);
    line[1].position = sf::Vector2f(to.x, to.y);
    line[0].color = sf::Color(lineColor);
    line[1].color = sf::Color(lineColor);

    m_window->draw(line);
}

void CCanvas::FillPolygon(std::vector<CPoint> points, uint32_t fillColor) const
{
    sf::ConvexShape polygon(points.size());
    for (size_t i = 0; i < points.size(); ++i)
    {
        polygon.setPoint(i, sf::Vector2f(points[i].x, points[i].y));
    }
    polygon.setFillColor(sf::Color(fillColor));

    m_window->draw(polygon);
}

void CCanvas::DrawCircle(CPoint center, double radius, uint32_t lineColor) const
{
    sf::CircleShape circle(static_cast<float>(radius));
    circle.setPosition({static_cast<float>(center.x - radius), static_cast<float>(center.y - radius)});
    circle.setOutlineThickness(1);
    circle.setOutlineColor(sf::Color(lineColor));
    circle.setFillColor(sf::Color::Transparent);

    m_window->draw(circle);
}

void CCanvas::FillCircle(CPoint center, double radius, uint32_t fillColor) const
{
    sf::CircleShape circle(static_cast<float>(radius));
    circle.setPosition({static_cast<float>(center.x - radius), static_cast<float>(center.y - radius)});
    circle.setFillColor(sf::Color(fillColor));

    m_window->draw(circle);
}