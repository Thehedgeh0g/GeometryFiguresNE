//
// Created by flipd on 13.04.2024.
//

#include <sstream>
#include <iomanip>
#include "ConvertColor.h"

std::string ConvertColor::ColorCodeToString(uint32_t color)
{

    int r(static_cast<std::uint8_t>((color & 0xff000000) >> 24));
    int g(static_cast<std::uint8_t>((color & 0x00ff0000) >> 16));
    int b(static_cast<std::uint8_t>((color & 0x0000ff00) >> 8));
    int a(static_cast<std::uint8_t>(color & 0x000000ff));

    std::ostringstream oss;
    oss << std::hex << std::setw(2) << std::setfill('0') << r;
    oss << std::hex << std::setw(2) << std::setfill('0') << g;
    oss << std::hex << std::setw(2) << std::setfill('0') << b;
    oss << std::hex << std::setw(2) << std::setfill('0') << a;
    auto result = "0x" + oss.str();
    return result;
}

uint32_t ConvertColor::ConvertColor::ParseColorCode(const std::string& colorCode)
{
    if (colorCode.size() != 7 || colorCode[0] != '#' ||
        colorCode.find_first_not_of("0123456789abcdefABCDEF", 1) != std::string::npos)
    {
        throw std::invalid_argument("Invalid color code format");
    }

    std::istringstream iss(colorCode.substr(1));
    uint32_t color = 0;
    iss >> std::hex >> color;

    return color;
}
