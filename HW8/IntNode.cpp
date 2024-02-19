#include "IntNode.h"
#include "IntList.h"
#include<iostream>

IntNode::IntNode( int new_value ) {
    payload = new_value;
    next = nullptr;
}

int IntNode::get_data() const {
    return payload;
}

void IntNode::set_next(IntNode* new_next) {
    next = new_next;
}

IntNode* IntNode::get_next() const {
    return next;
}

void IntNode::debug_write(std::ostream& outfile) const {
    outfile << payload << "(";
    if (next != nullptr) {
        outfile << "->" << next->payload;
    } else {
        outfile << "-> / ";
    }
    outfile << ")";
}

std::ostream& operator<<(std::ostream& outfile, const IntNode& node) {
    outfile << node.get_data() << "(";
    if (node.get_next() != nullptr) {
        outfile << "->" << node.get_next()->get_data();
    } else {
        outfile << "-> / ";
    }
    outfile << ")";
    return outfile;
}
