#include "Square.h"
#include<iostream>
#include "Shape.h"

using namespace std;

Square::Square( double x, double y, double s ) : Shape{x, y} {
  cout << "DEBUG: Executing Square constructor...\n";
  side = s;
}

void Square::write(ostream &fout) const {
  fout << "Side: " << side << endl;
  Shape::write(fout);
}

Square::Square( istream& in ) : Shape( in ) {
  in >> side;
}

Square::~Square() {
  std::cout << "executing Square destructor" << std::endl;
}
