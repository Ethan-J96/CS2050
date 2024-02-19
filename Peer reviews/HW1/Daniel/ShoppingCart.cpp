#include "ShoppingCart.h"
#include <iostream>

ShoppingCart::ShoppingCart() {}
 
void ShoppingCart::add(Item new_item)
{
    if (new_item.get_quantity() >= 1)                                  
    {
        bool item_in_list{false};    
                                     
        for (auto &item : cart)    
        {
            if (item.get_name() == new_item.get_name()
                && item.get_price() == new_item.get_price())                                   
            {
                item_in_list = true; 
                item.set_quantity(item.get_quantity() + new_item.get_quantity());                                                                      
            }
        }
        if (!item_in_list)  
            cart.push_back(new_item); 
    }
}

bool ShoppingCart::update_quantity(std::string name, int quantity)
{
    bool item_found{false};

    for (auto items = cart.begin(); 
         item_found == false && items != cart.end(); ++items)
    {
        if (items->get_name() == name)    
        {
            item_found = true;

            if (quantity >= 1) 
                items->set_quantity(quantity);
            else    
                cart.erase(items);
        }
    }

    return item_found;
}

bool ShoppingCart::remove(std::string name)
{
    bool item_found{false};

    for (auto items = cart.begin(); 
         item_found == false && items != cart.end(); ++items)
    {
        if (items->get_name() == name)
        {
            item_found = true;
            cart.erase(items);
        }
    }

    return item_found;
}


double ShoppingCart::total_value()
{
    double total{0};
    for (auto items = cart.begin(); items != cart.end(); ++items)
        total += items->get_price() * items->get_quantity();
    return total;
}

void ShoppingCart::write()
{
    for (auto &&item : cart)
        item.print();
    std::cout << "total value: " << this->total_value() << std::endl;
}