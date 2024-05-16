//
// Created by flipd on 12.04.2024.
//

#ifndef GEOMETRYFIGURES_ISOLIDSHAPE_H
#define GEOMETRYFIGURES_ISOLIDSHAPE_H

#include <cstdint>
#include "IShape.h"

class ISolidShape : public IShape
{
public:
    [[nodiscard]] virtual uint32_t GetFillColor() const = 0;
};

#endif //GEOMETRYFIGURES_ISOLIDSHAPE_H
