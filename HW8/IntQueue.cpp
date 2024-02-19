#include "IntQueue.h"
bool IntQueue::is_empty() const{
    return list.is_empty();
}
void IntQueue::enqueue(int operand){
    list.add_back(operand);
}
int IntQueue::dequeue(){
    return list.remove_front();
}
void IntQueue::debug_write(std::ostream& outfile) const{
    list.write(outfile);
}

std::ostream& operator<<(std::ostream& outfile, const IntQueue& queue){
    queue.debug_write(outfile);
    return outfile;
}