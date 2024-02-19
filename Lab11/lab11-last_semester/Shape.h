#ifndef SHAPE_H
#define SHAPE_H
#include<iostream>

class Shape {
public:
    Shape( double x, double y );
    virtual void write(std::ostream& strm_out) const;
    Shape( std::istream& in );
    virtual ~Shape(){   }
private:
    double ref_x;
    double ref_y;
};
std::ostream& operator<< (std::ostream& strm_out, const Shape& s);

#endif
