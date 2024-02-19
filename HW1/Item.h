#ifndef ITEM_H
#define ITEM_H
#include <string>

// ----------

class Item {
  public:
    Item(std::string name, double price, int quantity);
    //accessors
    std::string get_name() const;
    double get_price() const;
    int get_quantity() const;
    //mutators
    void set_price(double new_price);
    void set_quantity(int new_quantity);
  private:
    std::string name;
    double      price;
    int         quantity;
};

#endif