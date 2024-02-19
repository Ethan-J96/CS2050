#include "ItemNode.h"
#include <iostream>

ItemNode::ItemNode(Item new_item){
    payload = new_item;
    next = nullptr;
}
Item ItemNode::get_item( ) const{
    return payload;
}
ItemNode* ItemNode::get_next( ) const{
    return next;
}
void ItemNode::set_item( Item item){
    payload = item;
}
void ItemNode::set_next( ItemNode* node ){
    next = node;
}
std::ostream& ItemNode::write( std::ostream& fout ) const{
    payload.write(fout);
    if (next == nullptr) {
        fout << "(-----)";
    } else {
        fout << "(" << next->get_item() << ")";
    }
    fout << "/n";
    return fout;
}
std::ostream& operator<<( std::ostream& fout, const ItemNode& node ){
    return node.write(fout);
}

ItemNode::~ItemNode() { 
    std::cout << "Deleting " << payload.name << "..." << std::endl; 
} 
