#ifndef INTQUEUE_H_
#define INTQUEUE_H_
#include "IntList.h"
#include <iostream>

class IntQueue{
    public: 
        bool is_empty() const;
        void enqueue(int operand);
        int dequeue();
        void debug_write(std::ostream& outfile) const;
    private: 
        IntList list;
};

std::ostream& operator<<(std::ostream& outfile, const IntQueue& queue);

#endif 