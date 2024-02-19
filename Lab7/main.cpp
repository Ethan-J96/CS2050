#include "Item.h"
#include "ItemNode.h"
#include "ItemList.h"
#include<iostream>
#include <fstream>
#include <stdexcept>

int main() {
    std::ofstream dbg{"debug.txt"};  // open a file named debug.txt

    Item test_item{"Great Sword", 1};
    dbg << "test item: \n" << test_item << "\n" << std::endl;

    // List Nodes
    ItemNode test_node_1{ Item{"Amulet of Feasting", 2} };
    dbg << "test game item node: \n" << test_node_1 << "\n" << std::endl;

    ItemNode test_node_2{ Item{"Potion of Fire Walking", 3} };
    test_node_1.set_next( &test_node_2 );
    dbg << "test 2 items: \n"
    << test_node_1 << "\n"
    << test_node_2 << std::endl;

    // Adding to the head of an unordered list
    ItemList inventory1;

    inventory1.add_front(Item{"Stone Shield", 1});
    inventory1.add_front(Item{"Potion of Health", 1});

    // std::cout << inventory1 << std::endl; // Assuming operator<< is defined

    dbg << "inventory1 listings with 2 nodes (head: Potion of Health, tail: Stone Shield):\n"
    << inventory1 << "\n"
    << std::endl;

    // Adding to the tail of an unordered list
    inventory1.add_back(Item{"Cap of Health", 2});
    inventory1.add_back(Item{"Captain's Pike", 1});

    dbg << "inventory1 listings with 4 nodes (head: Potion of Health, tail: Captain's Pike):\n"
        << inventory1 << std::endl;

    ItemList inventory2;

    inventory2.add_back(Item{"Ruby Wand", 1});
    inventory2.add_back(Item{"Greatsword"});
    inventory2.add_front(Item{"Cloak of Shadows", 3});

    dbg << "inventory2 listings with 3 nodes (head: Cloak of Shadows, tail: Greatsword):\n"
        << inventory2 << std::endl;

    // Removing the head from the list
    try {
    Item first = inventory1.remove_front( );

    dbg << "removed from head of inventory1:\n"
        << first << "\n"
        << "inventory1 now:\n"
        << inventory1 << std::endl;
    } 
    catch ( const std::length_error& e ) { 
      dbg << e.what( ) << "\n"; 
    }

    //Erasing a list
    inventory2.erase ();
    dbg << "inventory2 listings after erase:\n" << inventory2 << "\n" << std::endl;

    return 0;
} 
