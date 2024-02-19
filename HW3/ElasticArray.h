#ifndef ELASTICARRAY_H_
#define ELASTICARRAY_H_

class ElasticArray{
    public:
        //ctors 
        ElasticArray() = default;
        ElasticArray(int size);
        // copy ctor, initialization list and data copying done inside the ctor
        ElasticArray(const ElasticArray& source) : _array(new int[source._size]), _size(source._size) {
                    for(int i = 0; i < source._size; i++){
                        _array[i] = source._array[i];}}

        //accessors:
        int  size() const { return _size; }
        int& at(int i); // also functions as a mutator, can read or write the data with the returned reference
        int front();
        int back();

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
            return *this; // return a REFERENCE to 'this', multiple assignments are possible
        }
    private:
        int* _array = nullptr;
        int  _size  = 0;
};

#endif