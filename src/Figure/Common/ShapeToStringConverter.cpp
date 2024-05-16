//
// Created by flipd on 21.04.2024.
//

#include "ShapeToStringConverter.h"
#include "ConvertColor.h"

std::string ShapeToStringConverter::ConvertToString(
    const std::string& shape,
    const std::vector<CPoint>& vertices,
    const std::vector<uint32_t>& colors,
    const std::vector<double>& otherNumericParams
)
{
    std::string result = shape + ' ';
    for (const auto& vertex: vertices)
    {
        result += std::to_string(vertex.x) + " " + std::to_string(vertex.y) + " ";
    }
    for (const auto& otherNumericParam: otherNumericParams)
    {
        result += std::to_string(otherNumericParam) + " ";
    }
    for (const auto& color: colors)
    {
        result += ConvertColor::ColorCodeToString(color) + " ";
    }
    return result;
}
