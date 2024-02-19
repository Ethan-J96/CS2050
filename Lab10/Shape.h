#ifndef SHAPE_H_
#define SHAPE_H_
#include <iostream>
using namespace std;
// Class Shape should be placed in Shape.h
class Shape {
public:
    Shape( double x, double y );
    void write(ostream& fout) const;
private:
    double ref_x;
    double ref_y;
};
ostream& operator<<(ostream& fout, const Shape&);
#endif 