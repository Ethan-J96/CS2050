#ifndef CSZNODE_H_
#define CSZNODE_H_
#include "CityStateZip.h"

class CSZNode { 
public:
    CSZNode( const CityStateZip& data ) : payload{data} {};
    void         set_left( CSZNode* new_left );
    void         set_right( CSZNode* new_right );
    CityStateZip get_data( ) const;
    CSZNode*&     get_left( );
    CSZNode*&     get_right( );

    void writeNode( std::ostream& fout ) const;
    bool operator<(const CSZNode& op2) const;
private:
    CityStateZip payload;
    CSZNode*     left  = nullptr;
    CSZNode*     right = nullptr;
};

std::ostream& operator<<( std::ostream& fout, const CSZNode& n );

#endif