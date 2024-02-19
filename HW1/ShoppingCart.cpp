#include "ShoppingCart.h"
#include "Item.h"
#include <algorithm>

void ShoppingCart::add_item(Item new_item){
    if(ItemCart.size() == 0){
        ItemCart.push_back(new_item);
    }
    else{
        auto it = find_if(ItemCart.begin(), ItemCart.end(),
        [&new_item](const Item& item_) { // lambda function to return a boolean for the find_if predicate 
            return (item_.get_name() == new_item.get_name())&&(item_.get_price() == new_item.get_price());
        });
        if(it == ItemCart.end()){
            ItemCart.push_back(new_item);
        }
        else if(it != ItemCart.end()){
            it->set_quantity(it->get_quantity() + new_item.get_quantity());
        }
    }
}
bool ShoppingCart::update_quantity(std::string item_name, int q_count){
    auto it = std::find_if(ItemCart.begin(), ItemCart.end(),
    [&item_name](const Item& item_) { // lambda function to return a boolean for the find_if predicate 
        return (item_.get_name() == item_name);
    });
    if(it == ItemCart.end()){
        return false;
    }
    else if(it != ItemCart.end()){
        if(q_count <= 0){
            ItemCart.erase(it);
        }
        else{
            it->set_quantity(q_count);
        }
        return true;
    }
    return false;
}
bool ShoppingCart::remove(std::string item_name){
    auto it = std::find_if(ItemCart.begin(), ItemCart.end(),
    [&item_name](const Item& item_) { // lambda function to return a boolean for the find_if predicate 
        return (item_.get_name() == item_name);
    });
    if(it == ItemCart.end()){
        return false;
    }
    else if(it != ItemCart.end()){
        ItemCart.erase(it);
        return true;
    }
    return false;
}
int ShoppingCart::total_value(){
    int total = 0;
    if(ItemCart.size() == 0){
        total = 0;
    }
    else{
        for(Item item_ : ItemCart){
            total += item_.get_price();
        }
    }
    return total;
}
void ShoppingCart::write(){
    for(Item item_ : ItemCart){
        printf("Item Name: %s, Item Price: %f, Item Quantity: %d\n", item_.get_name().c_str(), item_.get_price(), item_.get_quantity());
    }
}
