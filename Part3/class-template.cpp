/*
* 实现一个通用的数组类，要求如下：

* 可以对内置数据类型以及自定义数据类型的数据进行存储
* 将数组中的数据存储到堆区
* 构造函数中可以传入数组的容量
* 提供对应的拷贝构造函数以及operator=防止浅拷贝问题
* 提供尾插法和尾删法对数组中的数据进行增加和删除
* 可以通过下标的方式访问数组中的元素
* 可以获取数组中当前元素个数和数组的容量

*/

#include "class-template.h"
#include <iostream>
#include <string>

void printIntArray(Array<int> &arr) {
	for (int i = 0; i < arr.GetNum(); i++) { std::cout << arr[i] << " "; }
	std::cout << std::endl;
}

// 测试内置数据类型
void test01() {
	Array<int> array1(10);
	for (int i = 0; i < 10; i++) { array1.Push(i); }
	std::cout << "array1 output: " << std::endl;
	printIntArray(array1);
	std::cout << "array1 number: " << array1.GetNum() << std::endl;
	std::cout << "array1 capacity: " << array1.GetCapacity() << std::endl;

	std::cout << "--------------------------" << std::endl;

	Array<int> array2(array1);
	array2.Pop();
	std::cout << "array2 output: " << std::endl;
	printIntArray(array2);
	std::cout << "array2 number: " << array2.GetNum() << std::endl;
	std::cout << "array2 capacity: " << array2.GetCapacity() << std::endl;
}

// 测试自定义数据类型
class Person {
public:
	Person() {}
	Person(std::string name, int age) {
		this->m_Name = name;
		this->m_Age	 = age;
	}

public:
	std::string m_Name;
	int	   m_Age;
};

void printPersonArray(Array<Person> &personArr) {
	for (int i = 0; i < personArr.GetNum(); i++) {
		std::cout << "name: " << personArr[i].m_Name << " age:  "
				  << personArr[i].m_Age << std::endl;
	}
}

void test02() {
	// 创建数组
	Array<Person> pArray(10);
	Person		  p1("Sun", 30);
	Person		  p2("Han", 20);
	Person		  p3("Wang", 18);
	Person		  p4("Zhao", 15);
	Person		  p5("Wu", 24);

	// 插入数据
	pArray.Push(p1);
	pArray.Push(p2);
	pArray.Push(p3);
	pArray.Push(p4);
	pArray.Push(p5);

	printPersonArray(pArray);

    pArray.Pop();
    pArray.Pop();

	std::cout << "pArray number: " << pArray.GetNum() << std::endl;
	std::cout << "pArray Capacity: " << pArray.GetCapacity() << std::endl;
}

int main() {

    test01();

	test02();

	return 0;
}