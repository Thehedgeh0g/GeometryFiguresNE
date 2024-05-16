//
// Created by flipd on 12.04.2024.
//

#ifndef GEOMETRYFIGURES_CPOINT_H
#define GEOMETRYFIGURES_CPOINT_H


class CPoint
{
public:
    double x;
    double y;

    CPoint(double x, double y);

    //можно написать через auto
    bool operator==(CPoint other) const;

    bool operator!=(CPoint other) const;

};


#endif //GEOMETRYFIGURES_CPOINT_H
