#include "IntList.h"
#include "IntNode.h"
#include<iostream>

std::ostream& operator<<(std::ostream& outfile, const IntList& list);

IntList::~IntList() {
    while (this->head != nullptr) {
        this->remove_front();
    }
}

bool IntList::is_empty() const {
    return head == nullptr;
}

void IntList::add_front(int newData) {
    IntNode* new_node = new IntNode(newData);

    if (head == nullptr) {
        // List is empty, make new_node the head and tail
        head = new_node;
    } else {
        // List is not empty, add new_node to the head
        new_node->set_next(head);
        head = new_node;
    }
}

int IntList::remove_front() {
    if (head == nullptr) {
      throw std::length_error{ "Cannot remove from an empty list." };
    }
    IntNode* old_head = head;
    int result = old_head->get_data();
    head = old_head->get_next();
    delete old_head;
    return result;
}

void IntList::write(std::ostream& outfile) const {
    IntNode* current = head;
    while (current != nullptr) {
        outfile << *current << '\n'; 
        current = current->get_next();
    }
}

std::ostream& operator<<(std::ostream& outfile, const IntList& list) {
    list.write(outfile);
    return outfile;
}
