#ifndef QUEUE_H_
#define QUEUE_H_
#include "List.h"
#include <iostream>

template <typename ValueType>
class Queue{
    public: 
        bool is_empty() const;
        void enqueue(ValueType operand);
        ValueType dequeue();
        void debug_write(std::ostream& outfile) const;
    private: 
        List<ValueType> list;
};

template <typename ValueType> 
std::ostream& operator<<(std::ostream& outfile, const Queue<ValueType>& queue);

template <typename ValueType>
bool Queue<ValueType>::is_empty() const{
    return list.is_empty();
}

template <typename ValueType> 
void Queue<ValueType>::enqueue(ValueType operand){
    list.add_back(operand);
}

template <typename ValueType> 
ValueType Queue<ValueType>::dequeue(){
    return list.remove_front();
}

template <typename ValueType>
void Queue<ValueType>::debug_write(std::ostream& outfile) const{
    list.write(outfile);
}

template <typename ValueType> 
std::ostream& operator<<(std::ostream& outfile, const Queue<ValueType>& queue){
    queue.debug_write(outfile);
    return outfile;
}

#endif 