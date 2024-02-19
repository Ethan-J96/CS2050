#ifndef ITEMLIST_H_
#define ITEMLIST_H_
#include "Item.h"
#include "ItemNode.h"
#include <string>
#include <iostream>
#include <iomanip>

class ItemList {
public:
    ItemList( ) = default;
    std::ostream& write( std::ostream& fout ) const;
    void          add_front( const Item& new_item );
    void add_back( const Item& new_item);
    Item remove_front();
    void erase ( );
    ~ItemList();
    
private:
    ItemNode* head = nullptr;
    ItemNode* tail = nullptr;
};
std::ostream& operator<<( std::ostream& fout, const ItemList& list );
#endif