#include "Square.h"
#include "Shape.h"
#include<iostream>

using namespace std;

Square::Square( double x, double y, double s ) : Shape{x, y} {
  cout << "DEBUG: Executing Square constructor...\n";
  side = s;
}

void Square::write(ostream &fout) const {
  Shape::write(fout);
  fout << "Side: " << side << endl;
}

Square::Square( istream& in ) : Shape( in ) {
  in >> side;
}

Square::~Square() {
  std::cout << "executing Square destructor" << std::endl;
}
