/**
 *******************************************************************************
 * @file    ElasticArray.h
 * @brief   This is a header file which declares the class ElasticArray2

 * @remarks
 *      Course:        Computer Science 2124, Fall 2023
 *      Due Date:      Sunday, 1st October, 2023
 *      Instructor:    Mr. Mark Gilland
 *
 * @author  Shreyansh Bakhariya
 * @date    1st October, 2023
 *******************************************************************************
**/


#ifndef ELASTICARRAY_H  
#define ELASTICARRAY_H

class ElasticArray{
public:
   ElasticArray(int size);
   int  size() const;
   int& at(int i);
   const int& at(int i) const;
   ~ElasticArray();
   int* getData();
   ElasticArray() = default;
   int front() const;
   int back() const;
   ElasticArray(const ElasticArray& source);
   ElasticArray& operator=(const ElasticArray& source);

   void push_back(int value);
   int pop_back();
   void shrink_to_fit();
   int capacity() const { return _max_size; }
   int operator[](int i) const { return at(i); }
   int& operator[](int i) { return at(i); }
   typedef int* iterator;
   iterator begin() { return _array; }
   iterator end() { return _array + _size; }
   ElasticArray operator+(const ElasticArray& rhs) const;

private:
   int* _array = nullptr;
   int  _size  = 0;
   int _max_size = 0;
};

#endif