//
// Created by flipd on 12.04.2024.
//

#ifndef GEOMETRYFIGURES_CLINESEGMENT_H
#define GEOMETRYFIGURES_CLINESEGMENT_H


#include "IShape.h"
#include "CPoint.h"
#include "ICanvasDrawable.h"

class CLineSegment : public IShape, public ICanvasDrawable
{
public:
    CLineSegment(const CPoint& startPoint, const CPoint& endPoint, const uint32_t& outlineColor);

    ~CLineSegment() override;

    [[nodiscard]] std::uint32_t GetOutlineColor() const override;

    [[nodiscard]] const CPoint& GetStartPoint() const;

    [[nodiscard]] const CPoint& GetEndPoint() const;

    [[nodiscard]] double GetArea() const override;

    [[nodiscard]] double GetPerimeter() const override;

    [[nodiscard]] std::string ToString() const override;

    void Draw(std::shared_ptr<ICanvas> canvas) const override;

private:
    CPoint m_startPoint;
    CPoint m_endPoint;
    uint32_t m_outlineColor;
};


#endif //GEOMETRYFIGURES_CLINESEGMENT_H
