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
 * 静态多态：函数重载和运算符重载属于静态多态，复用函数名-----函数地址早绑定，编译阶段确定函数地址
 ! 动态多态：派生类和虚函数运行时多态------函数地址晚绑定，运行阶段确定函数地址
 */
/*
 * 动态多态的满足条件
 * - 有继承关系
 * - 子类重写父类的虚函数
 * 动态多态的使用
 ! 父类的指针或引用执行子类对象
*/
class Animal {
public:
	//* void speak() { cout << "动物会说话" << endl; }
	virtual void speak() { cout << "动物会说话" << endl; }
};

class Cat : public Animal {
public:
	// ! 重写 函数返回值的类型 函数名称 参数列表 完全相同
	// * 子类中virtual关键字可写可不写
	void speak() { cout << "小猫在说话" << endl; }
};

// * 地址早绑定，在编译阶段就确定了函数地址
// * 如果想让猫说话，需要将地址晚绑定，即在运行阶段绑定
// !需要将父类中的函数加上virtual关键字
// !就相当于重载函数，本来需要在同一作用域下才能重载，现virtual允许父子类间函数重载
void doSpeak(Animal &animal) // Animal& animal = cat
{
	animal.speak();
}

void test01() {
	Cat cat;
	// 此时调用的是父类的speak函数
	doSpeak(cat);
}
void test02() { cout << "sizeof(Animal) = " << sizeof(Animal) << endl; }

int main() {
	// test01();
	test02();
	system("pause");
}