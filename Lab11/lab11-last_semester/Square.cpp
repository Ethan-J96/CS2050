#include<iostream>
#include "Square.h"
#include"Shape.h"

Square::Square(double x, double y, double s) : Shape(x, y), side(s) {}

void Square::write(std::ostream& strm_out) const {
   // strm_out << "Square(" << ref_x << ", " << ref_y << ", " << side << ")";
  strm_out << "Square(";
  Shape::write(strm_out);
  strm_out << ", " << side << ")";
}

// void Square::write(ostream &fout) const {
//     fout << "Reference point: (" << ref_x << ", " << ref_y << ")" << endl;
// }

std::ostream& operator<<(std::ostream& strm_out, const Square& s) {
    s.write(strm_out);
    return strm_out;
}

Square::Square(std::istream& in ): Shape(in) {
  in >> side;
}

