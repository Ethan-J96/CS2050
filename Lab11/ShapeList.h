#ifndef SHAPELIST_H
#define SHAPELIST_H

#include "Shape.h"
#include <list>

class ShapeList : protected std::list<Shape*> {
public:
    ShapeList( ) = default;
    void add( Shape* newShape );
    void write( ostream& strm_out ) const;
    Shape* findClosestTo (double p_x, double p_y) const;
    friend ostream& operator<<( ostream& strm_out, const ShapeList& shapes );

    ~ShapeList();
    void erase();
};

#endif
