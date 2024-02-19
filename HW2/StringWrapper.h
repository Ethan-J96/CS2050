#ifndef STRINGWRAPPER_H_
#define STRINGWRAPPER_H_
#include <iostream>
#include <cstring>
#include <stdexcept>

class StringWrapper{
    public:
        StringWrapper(const char* new_string);
        ~StringWrapper();
        // Get a character at a specific index
        char get(int index) const;
        // Set a character at a specific index
        void set(int index, char value);
        // Write the string to an output stream (default: std::cout)
        void write(std::ostream& strm = std::cout) const;
        // Read a line from an input stream (default: std::cin) using a delimiter (default: newline)
        void readline(std::istream& strm = std::cin, char delim = '\n');
        const static int max_capacity = 1048576;
    private:
        char* c_string; // Pointer to the underlying C-string
};

#endif 