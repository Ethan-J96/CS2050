#include "IntList.h"
#include "IntNode.h"
#include "IntStack.h"
#include <iostream>

bool IntStack::is_empty() const {
  return list.is_empty();
}

void IntStack::push(int operand) {
  list.add_front(operand);
}

int IntStack::pop() {
  if (is_empty()) {
    throw std::length_error("Stack is empty");
  }
  int value = list.remove_front();
  return value;
}

void IntStack::debug_write(std::ostream& outfile) const {
  list.write(outfile);
}

std::ostream& operator<<(std::ostream& outfile, const IntStack& stack) {
  stack.debug_write(outfile);
  return outfile;
}
