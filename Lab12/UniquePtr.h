#ifndef UNIQUEPTR_H_
#define UNIQUEPTR_H_
#include "Foo.h"
#include <string>
template <typename T>
class UniquePtr{
    public:
        template <typename... Args>
        UniquePtr(const Args&... args) : _ptr{new T{args...}} { }
        ~UniquePtr();
        T& operator* () const;
        T* operator->() const;
        UniquePtr (const UniquePtr&)           = delete; // disallow copy construction
        UniquePtr& operator=(const UniquePtr&) = delete; // disallow assignment
    protected:
        T* _ptr;
};

template <typename T> 
class UniquePtr<T[]>{
    public:
        UniquePtr(int size){
            _array = new T[size];
        }
        ~UniquePtr();
        T& operator* () const;
        T& operator[](int i) const;
        UniquePtr (const UniquePtr&)           = delete; // disallow copy construction
        UniquePtr& operator=(const UniquePtr&) = delete; // disallow assignment
    protected:
        T* _array;
};

template <typename T>
UniquePtr<T>::~UniquePtr(){
    delete _ptr;
}
template <typename T>
T& UniquePtr<T>::operator* () const{
    return *_ptr;
}
template <typename T>
T* UniquePtr<T>::operator->() const{
    return _ptr;
}


template <typename T>
UniquePtr<T[]>::~UniquePtr(){
    delete[] _array;
}
template <typename T>
T& UniquePtr<T[]>::operator* () const{
    return *_array;
}

template <typename T>
T& UniquePtr<T[]>::operator[](int i) const{
    return _array[i];
}

#endif