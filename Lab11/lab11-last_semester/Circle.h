#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include<iostream>

class Circle : public Shape {
public:
    Circle(double x, double y, double r);
    void write(std::ostream& strm_out) const;
    Circle( std::istream& in );

private:
    double radius;
};

std::ostream& operator<<(std::ostream& strm_out, const Circle& c);

#endif
