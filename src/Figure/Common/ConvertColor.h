//
// Created by flipd on 13.04.2024.
//

#ifndef GEOMETRYFIGURES_CONVERTCOLOR_H
#define GEOMETRYFIGURES_CONVERTCOLOR_H


#include <cstdint>
#include <string>

class ConvertColor
{
public:
    static uint32_t ParseColorCode(const std::string& colorCode);

    static std::string ColorCodeToString(uint32_t color);
};


#endif //GEOMETRYFIGURES_CONVERTCOLOR_H
