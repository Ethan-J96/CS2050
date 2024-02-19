#ifndef NODE_H
#define NODE_H
#include <iostream>

template <typename ValueType>
class Node {
public:
    Node( ValueType new_value );
    ValueType get_data( ) const;
    void set_next( Node<ValueType>* new_next );
    Node<ValueType>* get_next( ) const;
    void debug_write( std::ostream& outfile ) const;

private:
    ValueType      payload;
    Node<ValueType>* next = nullptr;
};

template <typename ValueType> 
std::ostream& operator<<( std::ostream& outfile, const Node<ValueType>& node );

template <typename ValueType>
Node<ValueType>::Node( ValueType new_value ) {
    payload = new_value;
    next = nullptr;
}

template <typename ValueType> 
ValueType Node<ValueType>::get_data() const {
    return payload;
}

template <typename ValueType> 
void Node<ValueType>::set_next(Node<ValueType>* new_next) {
    next = new_next;
}

template <typename ValueType> 
Node<ValueType>* Node<ValueType>::get_next() const {
    return next;
}

template <typename ValueType> 
void Node<ValueType>::debug_write(std::ostream& outfile) const {
    outfile << payload << "(";
    if (next != nullptr) {
        outfile << "->" << next->payload;
    } else {
        outfile << "-> / ";
    }
    outfile << ")";
}

template <typename ValueType> 
std::ostream& operator<<(std::ostream& outfile, const Node<ValueType>& node) {
    outfile << node.get_data() << "(";
    if (node.get_next() != nullptr) {
        outfile << "->" << node.get_next()->get_data();
    } else {
        outfile << "-> / ";
    }
    outfile << ")";
    return outfile;
}

#endif