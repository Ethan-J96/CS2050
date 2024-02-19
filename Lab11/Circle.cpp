#include "Circle.h"
#include "Shape.h"
#include <iostream>

using namespace std; // dont have to use std:: a million times

Circle::Circle(double x, double y, double r) : Shape{x, y}, radius{r} {
  cout << "DEBUG: Executing Circle constructor...\n";
}

// write method only takes an output stream
void Circle::write(ostream &fout) const {
  Shape::write(fout);
  fout << "Radius: " << radius << endl;
}

Circle::Circle( istream& fin ) : Shape( fin ) {
  fin >> radius;
}

Circle::~Circle() {
  std::cout << "executing Circle destructor" << std::endl;
}

ostream& operator<<(ostream& fout, const Circle& c) {
  c.write(fout);
  return fout;
}