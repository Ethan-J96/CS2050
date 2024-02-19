
#include "ItemList.h"

std::ostream& ItemList::write( std::ostream& fout ) const{
    if(!head){
        fout << "The Linked List is empty" << std::endl;
    }
    ItemNode* current = head;
    while(current != nullptr)
    {
        current->write(fout);
        current = current->get_next();
        fout << "\n";
    }

    return(fout);
}
void ItemList::add_front( const Item& new_item ){
    ItemNode* new_itemNode = new ItemNode(new_item);
    if (head == nullptr){
        head = new_itemNode;
        tail = new_itemNode;
    }
    else{
        new_itemNode->set_next(head);
        head = new_itemNode;
    }
}
std::ostream& operator<<(std::ostream& fout, const ItemList& list) {
    return list.write(fout);
}

void ItemList::add_back(const Item& new_item) {
    ItemNode* new_node = new ItemNode(new_item);

    if (head == nullptr) {
        tail = new_node;
        head = new_node;
    } else { 
        tail->set_next(new_node);
        tail = new_node;
    }
}

Item ItemList::remove_front() {
    if (head == nullptr) {
      throw std::length_error{ "Cannot remove from an empty list." };
    }
    ItemNode* old_head = head;
    Item result = old_head->get_item();
    head = old_head->get_next();
    if (!head) {
      tail = nullptr;
    } 

    delete old_head;
    return result;
}

void ItemList::erase() {
    while (head != nullptr) {
        remove_front();
    }
}

ItemList::~ItemList() {
    erase();
} 
