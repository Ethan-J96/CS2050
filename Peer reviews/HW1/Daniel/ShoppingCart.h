#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <string> 
#include <vector>
#include "Item.h"
 
class ShoppingCart
{
    private:
    std::vector<Item> cart;

    public:
    ShoppingCart();
    void add(Item new_item); 
    bool update_quantity(std::string name, int quantity);
    bool remove(std::string name);
    double total_value();
    void write();

};


#endif