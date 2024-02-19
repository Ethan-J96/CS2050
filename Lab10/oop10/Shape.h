#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
using namespace std;
class Shape {
    public:
        Shape( double x, double y );
        void write(ostream &fout) const;
        Shape( istream& in );
        ~Shape();
    private:
        double ref_x;
        double ref_y;
};
ostream& operator<<(ostream& os, const Shape& );
#endif
