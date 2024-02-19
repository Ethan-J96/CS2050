#include "Shape.h"
#include<iostream>

using namespace std;

Shape::Shape(double x, double y) : ref_x{x}, ref_y{y} {
  cout << "DEBUG: Executing Shape constructor...\n";
}

void Shape::write(ostream &fout) const {
    fout << "Reference: (" << ref_x << ", " << ref_y << ")" << endl;
}


Shape::Shape( istream& in ) {
  in >> ref_x >> ref_y;
}

Shape::~Shape() {
  std::cout << "executing Shape destructor" << std::endl;
}

// Overload operator<< for Shape objects
ostream& operator<<(ostream& os, const Shape& s) {
  s.write(os);
  return os;
}