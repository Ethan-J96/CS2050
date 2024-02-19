#include<iostream>
#include "Shape.h"

using namespace std;

Shape::Shape(double x, double y) : ref_x(x), ref_y(y) {}

void Shape::write(std::ostream& strm_out) const {
  strm_out << "Shape(" << ref_x << ", " << ref_y << ")";
}

std::ostream& operator<<(std::ostream& strm_out, const Shape& s) {
  s.write(strm_out);
  return strm_out;
}

Shape::Shape( istream& in ) {
  in >> ref_x >> ref_y;
}

// void Shape::write(ostream &fout) const {
//     fout << "Reference point: (" << ref_x << ", " << ref_y << ")" << endl;
// }
