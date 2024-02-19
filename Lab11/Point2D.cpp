#include "Point2D.h"
#include<iostream>

using namespace std;

std::ostream& operator<<( std::ostream& strm, const Point2D& point ) {
    return strm << "(" << point.x << ", " << point.y << ")";
}
