#ifndef THINARRAYWRAPPER_H_
#define THINARRAYWRAPPER_H_
#include <iostream>

struct SuperThinArrayWrapper{
    int array[20];
};
struct ThinArrayWrapper{
    const static int size = 20;
    int array[size];
};

void print_array(SuperThinArrayWrapper a){
    for(int i = 0; i < 20; i++){
        std::cout << a.array[i] << " " << std::endl;
    }
}
void print_array(ThinArrayWrapper a){
    for(int i = 0; i < a.size; i++){
        std::cout << a.array[i] << " " << std::endl;
    }
}
void fill_array_v0(ThinArrayWrapper a){
    for(int i = 0; i < a.size; i++){
        std::cout << "Input Element " << i+1 << ": ";
        std::cin >> a.array[i];
        std::cout << std::endl;
    }
}

void fill_array_v1(ThinArrayWrapper& a){
    for(int i = 0; i < a.size; i++){
        std::cout << "Input Element " << i+1 << ": ";
        std::cin >> a.array[i];
        std::cout << std::endl;
    }
}

ThinArrayWrapper fill_array_v2(){
    struct ThinArrayWrapper a;
    for(int i = 0; i < a.size; i++){
        std::cout << "Input Element " << i+1 << ": ";
        std::cin >> a.array[i];
        std::cout << std::endl;

    }
    return a;
}

#endif