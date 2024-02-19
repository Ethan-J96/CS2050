#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_

class DynamicArray{
    public:
        DynamicArray(int size);
        int  size() const { return _size; }
        int& at(int i);
        ~DynamicArray();

    private:
        int* _array = nullptr;
        int  _size  = 0;
};

#endif