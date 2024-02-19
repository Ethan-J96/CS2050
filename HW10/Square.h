#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square : public Shape {
public:
  Square( double x, double y, double s );
  void write(ostream &fout) const;
  Square( istream& in );
  ~Square(); 

private:
  double side;
};

#endif
