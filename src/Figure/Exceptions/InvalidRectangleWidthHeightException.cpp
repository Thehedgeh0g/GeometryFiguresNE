//
// Created by flipd on 19.04.2024.
//

#include "InvalidRectangleWidthHeightException.h"

const char *InvalidRectangleWidthHeightException::what() const noexcept
{
    return "\"Height and width must be positive values.\"";
}
