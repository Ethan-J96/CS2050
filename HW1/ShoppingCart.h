#ifndef SHOPPINGCART_H_
#define SHOPPINGCART_H_
#include "Item.h"
#include <vector>
#include <iostream>
class ShoppingCart {
    public:
        ShoppingCart() {}
        void add_item(Item new_item);
        bool update_quantity(std::string item_name, int q_count);
        bool remove(std::string item_name);
        int total_value();
        void write();
    private: 
        std::vector<Item> ItemCart;
};

#endif