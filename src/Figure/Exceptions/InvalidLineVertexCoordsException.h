//
// Created by flipd on 19.04.2024.
//

#ifndef GEOMETRYFIGURES_INVALIDLINEVERTEXCOORDSEXCEPTION_H
#define GEOMETRYFIGURES_INVALIDLINEVERTEXCOORDSEXCEPTION_H


#include <exception>

class InvalidLineVertexCoordsException : public std::exception
{
    [[nodiscard]] const char *what() const noexcept override;
};


#endif //GEOMETRYFIGURES_INVALIDLINEVERTEXCOORDSEXCEPTION_H
