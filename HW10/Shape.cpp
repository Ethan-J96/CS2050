#include "Shape.h"
#include<iostream>
#include <cmath>

using namespace std;

Shape::Shape(double x, double y) : ref_x{x}, ref_y{y} {
  cout << "DEBUG: Executing Shape constructor...\n";
}

void Shape::write(ostream &fout) const {
  fout << "Reference: (" << ref_x << ", " << ref_y << ") ";
}


Shape::Shape( istream& in ) {
  in >> ref_x >> ref_y;
}

Shape::~Shape() {
  std::cout << "executing Shape destructor" << std::endl;
}

double Shape::getDistanceTo (double p_x, double p_y) const{
  double distance = sqrt(pow(p_x-ref_x, 2) + pow(p_y-ref_y, 2));
  return distance;
}

// Overload operator<< for Shape objects
ostream& operator<<(ostream& os, const Shape& s) {
  s.write(os);
  return os;
}