#include<iostream>
#include "Circle.h"

#include "Shape.h"

Circle::Circle(double x, double y, double r) : Shape(x, y), radius(r) {}

void Circle::write(std::ostream& strm_out) const {
    strm_out << "Circle(";
    Shape::write(strm_out);
    strm_out << ", " << radius << ")";
}

std::ostream& operator<<(std::ostream& strm_out, const Circle& s) {
    s.write(strm_out);
    return strm_out;
}

Circle::Circle( std::istream& in ): Shape(in) {
  in >> radius;
}
