#ifndef LIST_H
#define LIST_H
#include "Node.h"
#include <iostream>

template <typename ValueType>
class List {
public:
    List() = default;
    ~List();
    bool is_empty() const;
    void add_front(ValueType newData);
    void add_back(ValueType newData);
    ValueType remove_front();
    void write(std::ostream& outfile) const;
    List(const List<ValueType>&) = delete;
    List<ValueType>& operator=(const List<ValueType>&) = delete;
private:
    Node<ValueType>* head = nullptr;
    Node<ValueType>* tail = nullptr;
};

template <typename ValueType> std::ostream& operator<<(std::ostream& outfile, const List<ValueType>& list);

template <typename ValueType>
List<ValueType>::~List() {
    while (this->head != nullptr) {
        this->remove_front();
    }
}

template <typename ValueType>
bool List<ValueType>::is_empty() const {
    return head == nullptr;
}

template <typename ValueType>
void List<ValueType>::add_front(ValueType newData) {
    Node<ValueType>* new_node = new Node<ValueType>(newData);
    if (head == nullptr) {
        // List is empty, make new_node the head and tail
        head = new_node;
        tail = new_node;
    } else {
        // List is not empty, add new_node to the head
        new_node->set_next(head);
        head = new_node;
    }
}

template <typename ValueType>
void List<ValueType>::add_back(ValueType newData) {
    Node<ValueType>* new_node = new Node<ValueType>(newData);
    if (head == nullptr){
        head = new_node;
        tail = new_node;
    }
    else{
        tail->set_next(new_node);
        tail = new_node;
    }
}

template <typename ValueType>
ValueType List<ValueType>::remove_front() {
    if (head == nullptr) {
      throw std::length_error{ "Cannot remove from an empty list." };
    }
    Node<ValueType>* old_head = head;
    ValueType result = old_head->get_data();
    if(head->get_next() == tail){
        
    }
    head = old_head->get_next();
    delete old_head;
    return result;
}

template <typename ValueType> 
void List<ValueType>::write(std::ostream& outfile) const {
    Node<ValueType>* current = head;
    while (current != nullptr) {
        outfile << *current << '\n'; 
        current = current->get_next();
    }
}

template <typename ValueType>
std::ostream& operator<<(std::ostream& outfile, const List<ValueType>& list) {
    list.write(outfile);
    return outfile;
}

#endif
