//
// Created by flipd on 21.04.2024.
//

#ifndef GEOMETRYFIGURES_ICANVASDRAWABLE_H
#define GEOMETRYFIGURES_ICANVASDRAWABLE_H


#include <memory>
#include "../Canvas/ICanvas.h"

class ICanvasDrawable
{
public:
    virtual void Draw(std::shared_ptr<ICanvas> canvas) const = 0;
};

#endif //GEOMETRYFIGURES_ICANVASDRAWABLE_H
