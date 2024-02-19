#include "StringWrapper.h"
StringWrapper::StringWrapper(const char* new_string) {
    // Check if the input string exceeds the maximum capacity
    if (strlen(new_string) > max_capacity) {
        throw std::invalid_argument("Input string exceeds maximum capacity");
    }
    // Allocate memory for the underlying C-string
    c_string = new char[max_capacity];
    // Copy the input string into the underlying storage
    strncpy(c_string, new_string, strlen(new_string) + 1);
    c_string[strlen(new_string)] = '\0'; // Null-terminate at the end of the copied string
}

StringWrapper::~StringWrapper() {
    delete[] c_string;
}

char StringWrapper::get(int index) const {
    if (index < 0 || index >= strlen(c_string)) {
        throw std::out_of_range("Index out of range");
    }
    return c_string[index];
}

void StringWrapper::set(int index, char value) {
    if (index < 0 || index >= strlen(c_string)) {
        throw std::out_of_range("Index out of range");
    }
    c_string[index] = value;
}

void StringWrapper::write(std::ostream& strm) const {
    strm << c_string;
}

void StringWrapper::readline(std::istream& strm, char delim) {
    strm.getline(c_string, max_capacity, delim);
}