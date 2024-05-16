//
// Created by flipd on 19.04.2024.
//

#ifndef GEOMETRYFIGURES_INVALIDRECTANGLEWIDTHHEIGHTEXCEPTION_H
#define GEOMETRYFIGURES_INVALIDRECTANGLEWIDTHHEIGHTEXCEPTION_H


#include <exception>

class InvalidRectangleWidthHeightException : public std::exception
{
public:
    [[nodiscard]] const char *what() const noexcept override;

private:
    const char *m_message;
};


#endif //GEOMETRYFIGURES_INVALIDRECTANGLEWIDTHHEIGHTEXCEPTION_H
