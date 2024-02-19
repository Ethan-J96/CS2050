#include <iostream>
#include "Item.h"
#include <vector>
int main(){
    example();
    Item item1{ "Potato Chips", 1.78 };
    Item item2{ "Doritos", 1.99, 2 };
    // print item1's name
    std::cout << item1.get_name() << '\n';
    // Change item2's price to 2.49
    std::cout << "Original " << item2.get_name()  << '\n';
    std::cout << "Price:   " << item2.get_price() << '\n';
    item2.set_price(2.49);
    std::cout << "Updated  " << item2.get_name()  << '\n';
    std::cout << "Price:   " << item2.get_price() << '\n';
    std::vector<Item> ShoppingCart;
    std::string itemName;
    double itemPrice;
    while(true){
        std::cout << "Enter item name (enter nothing to exit): ";
        std::getline(std::cin,itemName);
        if (itemName.empty()){
            break;
        }
        std::cout << "Enter item price: ";
        std::cin >> itemPrice;
        std::cin.ignore();
        Item newItem(itemName,itemPrice,1);
        ShoppingCart.push_back(newItem);
    }
    std::cout << "Items added to the vector:" << std::endl;
    for (const Item& item : ShoppingCart) {
        std::cout << "Name: " << item.get_name() << ", Price: $" << item.get_price() << ", Quantity: " << item.get_quantity() << std::endl;
    }
    return 0;
}