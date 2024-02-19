#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"
#include<iostream>

class Square : public Shape {
public:
    Square(double x, double y, double s);
    void write(std::ostream& strm_out) const;
    Square( std::istream& in );

private:
    double side;
};

std::ostream& operator<<(std::ostream& strm_out, const Square& s);

#endif // SQUARE_H
