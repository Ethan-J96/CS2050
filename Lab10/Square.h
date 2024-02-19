#ifndef SQUARE_H_
#define SQUARE_H_
#include "Shape.h"
// Class Square should be placed in Square.h
class Square : public Shape {
public:
    Square( double x, double y, double s );
    void write(std::ostream& fout) const;
private:
    double side;
};

#endif