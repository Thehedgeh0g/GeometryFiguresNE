//
// Created by flipd on 12.04.2024.
//

#ifndef GEOMETRYFIGURES_CTRIANGLE_H
#define GEOMETRYFIGURES_CTRIANGLE_H


#include "ISolidShape.h"
#include "CPoint.h"
#include "ICanvasDrawable.h"

class CTriangle : public ISolidShape, public ICanvasDrawable
{
public:
    CTriangle(
        CPoint vertex1,
        CPoint vertex2,
        CPoint vertex3,
        uint32_t outlineColor,
        uint32_t fillColor
    );

    ~CTriangle() override;

    [[nodiscard]] uint32_t GetOutlineColor() const override;

    [[nodiscard]] uint32_t GetFillColor() const override;

    CPoint GetVertex1();

    CPoint GetVertex2();

    CPoint GetVertex3();

    [[nodiscard]] double GetArea() const override;

    [[nodiscard]] double GetPerimeter() const override;

    [[nodiscard]] std::string ToString() const override;

    void Draw(std::shared_ptr<ICanvas> canvas) const override;

private:
    CPoint m_vertex1;
    CPoint m_vertex2;
    CPoint m_vertex3;
    uint32_t m_outlineColor;
    uint32_t m_fillColor;
};


#endif //GEOMETRYFIGURES_CTRIANGLE_H
