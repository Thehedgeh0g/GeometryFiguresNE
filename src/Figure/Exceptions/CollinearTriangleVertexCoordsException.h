//
// Created by flipd on 19.04.2024.
//

#ifndef GEOMETRYFIGURES_COLLINEARTRIANGLEVERTEXCOORDSEXCEPTION_H
#define GEOMETRYFIGURES_COLLINEARTRIANGLEVERTEXCOORDSEXCEPTION_H


#include <exception>

class CollinearTriangleVertexCoordsException : public std::exception
{
public:
    [[nodiscard]] const char *what() const noexcept override;
};


#endif //GEOMETRYFIGURES_COLLINEARTRIANGLEVERTEXCOORDSEXCEPTION_H
