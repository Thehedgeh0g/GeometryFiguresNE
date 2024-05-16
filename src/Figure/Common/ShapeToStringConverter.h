//
// Created by flipd on 21.04.2024.
//

#ifndef GEOMETRYFIGURES_SHAPETOSTRINGCONVERTER_H
#define GEOMETRYFIGURES_SHAPETOSTRINGCONVERTER_H


#include <string>
#include <vector>
#include <cstdint>
#include "../Shapes/CPoint.h"

class ShapeToStringConverter
{
public:
    static std::string ConvertToString(
        const std::string& shape,
        const std::vector<CPoint>& vertices,
        const std::vector<uint32_t>& colors,
        const std::vector<double>& otherNumericParams
    );
};


#endif //GEOMETRYFIGURES_SHAPETOSTRINGCONVERTER_H
