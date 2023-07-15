/**
 * @file polymorphism.cpp
 * @author Melmaphother (Melmaphother@gmail.com)
 * @brief about polymorphism in c++
 * @version 0.1
 * @date 2023-07-15
 * 
 * @copyright Copyright (c) Melmaphother
 * 
 */

#include <iostream>
#include <string>
using namespace std;

/*
 * 多态分为两类
 * 静态多态：函数重载和运算符重载属于静态多态，复用函数名----- 函数地址早绑定，编译阶段确定函数地址
 ! 动态多态：派生类和虚函数运行时多态------ 函数地址晚绑定，运行阶段确定函数地址
*/
class Animal{
    public:
    void speak(){
        cout <<"动物会说话"<<endl;
    }
};

class Cat : public Animal{
    public:
    void speak() {
        cout << "小猫在说话" << endl;
     }

};
void doSpeak(Animal& animal){
    animal.speak();
}
void test01(){
    Cat cat;
    doSpeak(cat);
}


int main(){
    test01();
    system("pause");
}