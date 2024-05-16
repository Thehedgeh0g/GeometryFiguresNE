//
// Created by flipd on 12.04.2024.
//

#ifndef GEOMETRYFIGURES_ISHAPE_H
#define GEOMETRYFIGURES_ISHAPE_H

#include <string>
#include <cstdint>
#include "ICanvasDrawable.h"

class IShape : public ICanvasDrawable
{
public:
    [[nodiscard]] virtual double GetArea() const = 0;

    [[nodiscard]] virtual double GetPerimeter() const = 0;

    [[nodiscard]] virtual std::string ToString() const = 0;

    [[nodiscard]] virtual std::uint32_t GetOutlineColor() const = 0;

    virtual ~IShape() = default;
};

#endif //GEOMETRYFIGURES_ISHAPE_H
