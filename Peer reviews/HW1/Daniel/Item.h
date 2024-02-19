#ifndef ITEM_H
#define ITEM_H

#include <string> 

//void example();

class Item
{
    public:
        Item();
        Item(std::string name, double price, int quantity) : name{name}, price{price}, quantity{quantity}{}
        std::string get_name() const;       // accessor for items name 
        double  get_price() const {return price;}
        int     get_quantity() const; 
        void    set_price(double new_price) {price = new_price;}
        void    set_quantity(int new_quantity);
        void    set_name(std::string new_name);
        void print() const; 
    private:
        std::string name;
        double      price;
        int         quantity;
};
#endif