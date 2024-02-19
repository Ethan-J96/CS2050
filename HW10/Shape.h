#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
using namespace std;
class Shape {
    public:
        Shape( double x, double y );
        virtual void write(ostream &fout) const;
        Shape( istream& in );
        virtual ~Shape();
        double getDistanceTo (double p_x, double p_y) const;
    private:
        double ref_x;
        double ref_y;
};
ostream& operator<<(ostream& os, const Shape& );
#endif
