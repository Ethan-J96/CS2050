#ifndef SHAPELIST_H
#define SHAPELIST_H

#include <list>
#include "Shape.h"

#include<iostream>

class ShapeList : protected std::list<Shape*> {
public:
    ShapeList( ) = default;
    void add( Shape* newShape );
    void write( std::ostream& strm_out ) const;

    friend std::ostream& operator<<( std::ostream& strm_out, const ShapeList& shapes );

    ~ShapeList();
    void erase();
};

#endif
