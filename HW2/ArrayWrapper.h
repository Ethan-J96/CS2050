#ifndef ARRAYWRAPPER_H_
#define ARRAYWRAPPER_H_
#include <iostream>

class ArrayWrapper{
    public:
        ArrayWrapper(int _size) : size(_size) {
            for (int i = 0; i < max_capacity; i++) {
            array[i] = 0;
            }
        };
        int get_size() const;
        int get(int index) const;
        void set(int index, int value);

        const static int max_capacity = 262144; // 1MiB max size (1MiB / sizeof(int))
    private:
        int array[max_capacity];    // internal storage (partially-filled array)
        int size = 0;               // logical size (how many elements are used)
};
#endif