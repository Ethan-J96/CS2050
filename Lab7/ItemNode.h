#ifndef ITEMNODE_H_
#define ITEMNODE_H_
#include "Item.h"
#include <iostream>

class ItemNode {
public:
    ItemNode(Item new_item);
//accessors
    Item          get_item( ) const; //return the payload
    ItemNode*     get_next( ) const; //return the next pointer
//mutators
    void          set_item( Item item);
    void          set_next( ItemNode* node ); // set the "next" pointer
    std::ostream& write( std::ostream& fout ) const; //write the current node

    ~ItemNode();
private:
    Item      payload{"---", -1};
    ItemNode* next = nullptr;
};
std::ostream& operator<<( std::ostream& fout, const ItemNode& node );
#endif
