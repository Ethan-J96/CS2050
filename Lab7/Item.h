#ifndef ITEM_H_
#define ITEM_H_

#include <iostream>
#include <iomanip>
#include <string>

struct Item {
    Item(std::string name, int magic=0)
        : name{name}, magic{magic} {}
    std::string name;       // Item name
    int         magic = 0;  // Amount of "magic" the item is imbued with

    std::ostream& write( std::ostream& fout ) const;
};
std::ostream& operator<<( std::ostream& fout, const Item& item );

#endif