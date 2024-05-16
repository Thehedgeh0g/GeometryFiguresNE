//
// Created by flipd on 12.04.2024.
//

#ifndef GEOMETRYFIGURES_CCIRCLE_H
#define GEOMETRYFIGURES_CCIRCLE_H


#include <memory>
#include "ISolidShape.h"
#include "CPoint.h"
#include "ICanvasDrawable.h"


class CCircle : public ICanvasDrawable, public ISolidShape
{
public:

    CCircle(const CPoint& center, double radius, uint32_t outlineColor, uint32_t fillColor);

    ~CCircle() override;

    [[nodiscard]] double GetArea() const override;

    [[nodiscard]] double GetPerimeter() const override;

    [[nodiscard]] std::string ToString() const override;

    [[nodiscard]] uint32_t GetOutlineColor() const override;

    [[nodiscard]] uint32_t GetFillColor() const override;

    [[nodiscard]] const CPoint& GetCenter() const;

    [[nodiscard]] double GetRadius() const;

    void Draw(std::shared_ptr<ICanvas> canvas) const override;

private:
    CPoint m_center;
    double m_radius;
    uint32_t m_outlineColor;
    uint32_t m_fillColor;
};


#endif //GEOMETRYFIGURES_CCIRCLE_H
