#include "ShoppingCart.h"
#include "Item.h"
int main(){
    std::cout << "Creating list of items..." << std::endl;
    Item item1("Rognok the planet consumer", 30, 1);
    Item item2("Mogwyn the crimson apostle", 20, 1);
    Item item3("Malena the undying blade", 150, 1);
    Item item4("Leon the Glorious Champion", 2000, 1);
    Item item4_2("Leon the Glorious Champion", 100, 1);
    Item item5("Milk", 5, 1);
    Item item5_2("Milk", 5, 1);

    std::cout << "\nCreating ShoppingCart and adding items to the cart." << std::endl;
    ShoppingCart Cart;
    Cart.add_item(item1);
    Cart.add_item(item2);
    Cart.add_item(item3);
    Cart.add_item(item4);
    std::cout << "Adding duplicate items to the cart..." << std::endl;
    Cart.add_item(item4_2);
    Cart.add_item(item5);
    Cart.add_item(item5_2);
    std::cout << "Displaying cart..." << std::endl;
    Cart.write();

    std::cout << "\ntotal_value(): ";
    std::cout << Cart.total_value() << std::endl;

    std::cout << "\nUpdating quantity of several items and displaying..." << std::endl;
    Cart.update_quantity("Milk", 1);
    Cart.update_quantity("Chocolate Milk", 2);
    Cart.update_quantity("Mogwyn the crimson apostle", 0);
    Cart.update_quantity("Malena the undying blade", 2);

    Cart.write();

    std::cout << "\nRemoving Leon the Glorious Champion and displaying..." << std::endl; 
    Cart.remove("Leon the Glorious Champion");
    Cart.write();

    std::cout << "\ntotal_value(): ";
    std::cout << Cart.total_value() << std::endl;

    return 0;
}