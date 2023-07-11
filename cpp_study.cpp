#include <iostream>
#include <Windows.h>

template<typename T>
void myPrint(T a, T b){
    std::cout << "transfer function template" << std::endl;
}



int main(){ 
    int a, b;
    myPrint<int>(a, b);
    system("pause");
}
