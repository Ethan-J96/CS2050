#include "Item.h"
#include <iostream>


Item::Item()
{
}




std:: string Item::get_name() const {return name;}

int Item::get_quantity() const {return quantity;}

void Item::set_name(std::string new_name){name = new_name;}

void Item::set_quantity(int new_quantity) {quantity = new_quantity;}

void Item::print( ) const 
{
    std::cout << name << '\n';
    std::cout << "\tPrice: $  " << price << '\n';
    std::cout << "\tQuantity: " << quantity << '\n';
}
