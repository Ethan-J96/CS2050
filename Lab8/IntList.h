#ifndef INTLIST_H
#define INTLIST_H
#include "IntNode.h"
#include<iostream>

class IntList {
public:
    IntList() = default;
    ~IntList();
    bool is_empty() const;
    void add_front(int newData);
    int remove_front();
    void write(std::ostream& outfile) const;
    IntList(const IntList&) = delete;
    IntList& operator=(const IntList&) = delete;

private:
    IntNode* head = nullptr;
};

std::ostream& operator<<(std::ostream& outfile, const IntList& list);

#endif
