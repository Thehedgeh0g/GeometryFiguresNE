//
// Created by flipd on 21.04.2024.
//

#ifndef GEOMETRYFIGURES_CCANVAS_H
#define GEOMETRYFIGURES_CCANVAS_H


#include "ICanvas.h"
#include <SFML/Graphics.hpp>

class CCanvas : public ICanvas
{
public:
    CCanvas(std::shared_ptr<sf::RenderWindow> window) : m_window(std::move(window))
    {};

    void DrawLine(CPoint from, CPoint to, uint32_t lineColor) const override;

    void FillPolygon(std::vector<CPoint> points, uint32_t fillColor) const override;

    void DrawCircle(CPoint center, double radius, uint32_t lineColor) const override;

    void FillCircle(CPoint center, double radius, uint32_t fillColor) const override;

private:
    std::shared_ptr<sf::RenderWindow> m_window;
};


#endif //GEOMETRYFIGURES_CCANVAS_H
