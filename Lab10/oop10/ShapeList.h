#ifndef SHAPELIST_H
#define SHAPELIST_H

#include <list>
#include "Shape.h"

class ShapeList : protected std::list<Shape*> {
public:
    ShapeList( ) = default;
    void add( Shape* newShape );
    void write( ostream& strm_out ) const;

    friend ostream& operator<<( ostream& strm_out, const ShapeList& shapes );

    ~ShapeList();
    void erase();
};

#endif
