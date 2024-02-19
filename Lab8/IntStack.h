#ifndef INTSTACK_H
#define INTSTACK_H
#include "IntNode.h"
#include "IntList.h"
#include<iostream>

class IntStack {
public:
    bool is_empty( ) const;
    void push( int operand );
    int  pop( );
    void debug_write( std::ostream& outfile ) const;

private:
    IntList list; 
};
std::ostream& operator<<( std::ostream& outfile, const IntStack& stack );

#endif
