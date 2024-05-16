//
// Created by flipd on 12.04.2024.
//

#ifndef GEOMETRYFIGURES_CRECTANGLE_H
#define GEOMETRYFIGURES_CRECTANGLE_H


#include "ISolidShape.h"
#include "CPoint.h"
#include "ICanvasDrawable.h"

class CRectangle : public ISolidShape, public ICanvasDrawable
{
public:
    CRectangle(
        CPoint leftBottomVertex,
        double height,
        double width,
        uint32_t outlineColor,
        uint32_t fillColor
    );

    ~CRectangle() override;

    [[nodiscard]] uint32_t GetOutlineColor() const override;

    [[nodiscard]] uint32_t GetFillColor() const override;

    [[nodiscard]] const CPoint& GetLeftBottomVertex() const;

    [[nodiscard]] double GetArea() const override;

    [[nodiscard]] double GetPerimeter() const override;

    [[nodiscard]] std::string ToString() const override;

    void Draw(std::shared_ptr<ICanvas> canvas) const override;

private:
    CPoint m_leftBottomVertex;
    double m_height{};
    double m_width{};
    uint32_t m_outlineColor;
    uint32_t m_fillColor;
};


#endif //GEOMETRYFIGURES_CRECTANGLE_H
