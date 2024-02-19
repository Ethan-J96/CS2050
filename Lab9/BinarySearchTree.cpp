#include "BinarySearchTree.h"

//void add_recursively( const CityStateZip& new_city );
void BinarySearchTree::add_iteratively( const CityStateZip& new_city ){
    CSZNode* new_node = new CSZNode(new_city);
    CSZNode* current = root;
    CSZNode* previous;
    if(root != nullptr){
        while(current != nullptr){
            previous = current;
            if(*new_node < *current){
                current = current->get_left();
            }
            else{
                current = current->get_right();
            }
        }
        if(*new_node < *previous){
            previous->set_left(new_node);
        }
        else{
            previous->set_right(new_node);
        }
    }
    else{
        root = new_node;
    }
}
void BinarySearchTree::write_recursively( std::ostream& strm ) const{
    write_recursively(strm, root);
}
void BinarySearchTree::write_recursively( std::ostream& strm, CSZNode* current_root ) const{
    // !!! FIRST ATTEMPT !!!
    // if( current_root->get_left() != nullptr){
    //     write_recursively(strm, current_root->get_left());
    // }
    // strm << current_root << " ";
    // if( current_root->get_right() != nullptr){
    //     write_recursively(strm, current_root->get_right());
    // }
    
    /* after having chat gpt review the method it showed me a way to check the 
    base case at the beginning of the method call and then simply return
    instead of checking the base case before each call to the method 
    like I was doing.*/
    if(current_root == nullptr){
        return;
    }

    write_recursively(strm, current_root->get_left());
    strm << *current_root;
    write_recursively(strm, current_root->get_right());
}
// void write_iteratively( std::ostream& strm ) const;