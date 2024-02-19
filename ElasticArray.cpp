#include "ElasticArray.h"

ElasticArray destArr = sourceArr; 

ElasticArray destArr; 
destArr = sourceArr; 

void test_ElasticArray_copy_ctor(ElasticArray a){
    for(int i = 0; i < a.size(); ++i){
        a.at(i) = 999;  // just a value that will be easy to notice when printed.
    }
}

void front()
{
    ElasticArray.pushback();
}

void back()
{
    ElasticArray.pushup();
}

int size()
{
    return _size;
}

int& at(int i)
{
    return ElasticArray[i];
}

const int capacity()
{
    return _max_size;
}

void push_back(int i)
{
    if(_max_size > _size)
    {
        ElasticArray[i] = i;
        ElasticArray.pushback();
    }
    else if (_max_size == _size)
    {
        new ElasticArray[ElasticArray[] * ElasticArray[]];

        delete ElasticArray[];
    }
}

int pop_back()
{
    if(ElasticArray._size <= 0)
    {
        cout << std::out_of_range << "Cannot perform pop_back() on an empty container." << std::endl;
    }
    else{
        ElasticArray._size--;
    }

    return ElasticArray._size;
}

void shrink_to_fit()
{
    ElasticArray arr[new_size];
    if(new_size > 0)
    {
        arr = ElasticArray[];
        arr[i] = ElasticArray[];
        this.arr = this.ElasticArray[];
    }
    else if(new_size == 0)
    {
        this.arr = this.ElasticArray[];
        this.arr == nullptr;
        arr.new_size = 0;
    }
}

int begin()
{
    return ElasticArray[0];
}
int end()
{
    return ElasticArray[_size - 1];
}

int& operator[int i]
{
    return at();
}

 ElasticArray operator+(const ElasticArray& rhs) const
 {
    ElasticArray destArr[];
    for(int i = 0; i < destArr - 1; i++)
    {
        destArr[i] = this.ElasticArray[i];
    }
    for(int destArr[i] = 0; destArr[i] < _max_size; i++)
    {
         this.destArr[i] = ElasticArray[i];
    }
    return destArr;
 }

 ElasticArray operator+(const ElasticArray& arr);

