//
// Created by flipd on 19.04.2024.
//

#ifndef GEOMETRYFIGURES_INVALIDCIRCLERADIUSEXCEPTION_H
#define GEOMETRYFIGURES_INVALIDCIRCLERADIUSEXCEPTION_H


#include <exception>

class InvalidCircleRadiusException : public std::exception
{
    [[nodiscard]] const char *what() const noexcept override;
};


#endif //GEOMETRYFIGURES_INVALIDCIRCLERADIUSEXCEPTION_H
