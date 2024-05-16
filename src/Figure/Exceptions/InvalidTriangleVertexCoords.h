//
// Created by flipd on 19.04.2024.
//

#ifndef GEOMETRYFIGURES_INVALIDTRIANGLEVERTEXCOORDS_H
#define GEOMETRYFIGURES_INVALIDTRIANGLEVERTEXCOORDS_H


#include <exception>

class InvalidTriangleVertexCoords : public std::exception
{
public:
    [[nodiscard]] const char *what() const noexcept override;
};


#endif //GEOMETRYFIGURES_INVALIDTRIANGLEVERTEXCOORDS_H
