/**
 *******************************************************************************
 * @file    main.cpp
 * @brief   
 *
 * @remarks
 *      Course:        Computer Science 2124, Fall 2023
 *      Due Date:      9/07/2023
 *      Instructor:    Steaven
 *
 * @author  Daniel Delgadillo 
 * @date    9/07/2023
 *******************************************************************************
**/
#include <iostream>
#include "ShoppingCart.h"
#include <vector>
#include <string>

int main()
{
    const Item item1{"chips", 2.5, 3};
    Item item1_1{"Soda", 4.5, 3};
    Item item2{"Orange", 1.4, 1};

    ShoppingCart cartItem;

    std:: cout << "\n Value before adding items: " << cartItem.total_value() << std::endl;
    // test add()
    cartItem.add(item1);
    cartItem.add(item1_1);
    cartItem.add(item2);
    cartItem.add(item1);
    cartItem.write();

    // test total_value()
    std::cout << "Value in the cart  "<< cartItem.total_value() << std::endl;

    // test remove()
    cartItem.remove("item1");
    // cartItem.write();

    // test update_quantity()
    std::cout << cartItem.update_quantity("item1", 0) << std::endl;
    std::cout << cartItem.update_quantity("item2", 20) << std::endl;
    std::cout << cartItem.update_quantity("not exist", 10) << std::endl;
    std::cout << cartItem.update_quantity("not exist", 0) << std::endl;
    cartItem.write();

    
    return 0;
}