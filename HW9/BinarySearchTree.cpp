#include "BinarySearchTree.h"
#include <stack>
void BinarySearchTree::add_recursively( CSZNode* new_node, CSZNode*& current_root ){
    if(current_root == nullptr){
        current_root = new_node;
    }
    else{
        if(*new_node < *current_root){
            add_recursively(new_node, current_root->get_left());
        }
        else{
            add_recursively(new_node, current_root->get_right());
        }
    }
}
void BinarySearchTree::add_recursively( const CityStateZip& new_city ){
    CSZNode* new_node = new CSZNode(new_city);
    add_recursively(new_node, root);
    
}
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
void BinarySearchTree::write_iteratively( std::ostream& strm ) const{
    if(root != nullptr){
        std::stack<CSZNode*> nodeStack;
        CSZNode* current = root;
        while (current || !nodeStack.empty()) {
            while (current) {
                nodeStack.push(current);
                current = current->get_left();
            }
            current = nodeStack.top();
            nodeStack.pop();
            strm << *current << ' ';
            current = current->get_right();
        }
    }
}
void BinarySearchTree::erase_recursively(){
    erase_recursively(root);
}
void BinarySearchTree::erase_recursively(CSZNode* currentRoot){
    if (currentRoot == nullptr) {
        return; // Base case: Do nothing if the current node is nullptr.
    }
    if(currentRoot->get_left() != nullptr){
        erase_recursively(currentRoot->get_left());
    }
    if(currentRoot->get_right() != nullptr){
        erase_recursively(currentRoot->get_right());
    }
    delete currentRoot;
}