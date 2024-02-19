#ifndef ELASTICARRAY_H_
#define ELASTICARRAY_H_
#include <iostream>

class ElasticArray{
    public:
        //ctors 
        ElasticArray() = default;
        ElasticArray(int size);
        // copy ctor, initialization list and data copying done inside the ctor
        ElasticArray(const ElasticArray& source) : _array(new int[source._max_size]), _size(source._size), _max_size(source._max_size) {
                    for(int i = 0; i < source._size; i++){
                        _array[i] = source._array[i];}}

        //accessors:
        int  size() const { return _size; }
        int& at(int i); // also functions as a mutator, can read or write the data with the returned reference
        int front();
        int back();
        int capacity() const { return _max_size; }

        //elastic functionality 
        void push_back(int a);//insert parameter into end of arrray
        int pop_back();//return value of the item at end of the array and then remove it 
        void shrink_to_fit();//shrink the internal storage to match the current logical size
        int* begin();//return an iterator to the front of the array
        int* end();//return an iterator to the next byte following the end of the array


        // output
        void display() const {
            std::cout << "Size: " << _size << std::endl;
            std::cout << "Capacity: " << _max_size << std::endl;
            
            std::cout << "Elements in the array: ";
            for (int i = 0; i < _size; i++) {
                std::cout << _array[i] << " ";
            }
            std::cout << std::endl;
        }

        //destructor 
        ~ElasticArray();

        //assignment operator overload
        ElasticArray& operator=(const ElasticArray& source){
            delete[] _array; // release the old memory
            _size = source._size;
            _array = new int[_size];
            for(int i = 0; i < _size; i++){ //copy data over
                _array[i] = source._array[i];
            }
            _max_size = _size;
            return *this; // return a REFERENCE to 'this', multiple assignments are possible
        }
        int& operator[](int index){//return a reference to the given index in the array
            return at(index);
        }
        ElasticArray operator+(const ElasticArray& source) const{//enable concatenation of elasticarray objects
            ElasticArray sum(_size+source._size);
            std::cout << "\n" <<  _size << " " << source._size << std::endl;
            for(int i = 0; i < _size; i++){
                sum._array[i] = _array[i];
            }
            for (int i = 0; i < source._size; i++) {
                sum._array[_size + i] = source._array[i];
            }
            return sum;
        }

    private:
        int* _array = nullptr;
        int  _size  = 0;
        int _max_size = 0;
};

/* To resize larger from orig_size to new_size:
    1. create a new array whose size is new_size
    2. copy all elements from the current array into the new array
    3. de-allocate the memory associated with the current array
    4. point the internal array pointer attribute to the new array
    5. set the internal size attribute to the new size
*/
#endif