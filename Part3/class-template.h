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

#pragma once
#include <iostream>

template <typename T> class Array {
public:
	Array(unsigned capacity);
	Array(const Array &a);
	Array &operator=(const Array &a);
	~Array();

public:
	T	 operator[](unsigned index) const;
	void Push(T elem);
	void Pop();

public:
	unsigned GetNum() const;
	unsigned GetCapacity() const;

private:
	T		*array;	   //* 数组指针
	unsigned capacity; //* 数组的容量
	unsigned num;	   //* 数组中元素的个数
};

template <typename T> Array<T>::Array(unsigned capacity) {
	this->capacity = capacity;
	num			   = 0;
	array		   = new T[capacity];
}

template <typename T> Array<T>::Array(const Array &a) {
	capacity = a.capacity;
	num		 = a.num;
	array	 = new T[num];
	for (size_t i = 0; i < num; i++) { array[i] = a.array[i]; }
}

template <typename T> Array<T> &Array<T>::operator=(const Array &a) {
	if (array != NULL) { delete[] array; }
	num		 = a.num;
	capacity = a.capacity;
	array	 = new T[num];
	for (size_t i = 0; i < num; i++) { array[i] = a.array[i]; }
}

template <typename T> Array<T>::~Array() {
	if (array != NULL) {
		delete[] array;
		capacity = 0;
		num		 = 0;
		array	 = NULL;
	}
}

template <typename T> T Array<T>::operator[](unsigned index) const {
	if (index < num) return array[index];
	std::cout << "The index is out of range!" << std::endl;
	exit(0);
}

template <typename T> void Array<T>::Push(T elem) {
	if (capacity == num) {
		std::cout << "The array is full!" << std::endl;
		return;
	}
	array[num] = elem;
	num++;
}

template <typename T> void Array<T>::Pop() {
	if (num == 0) {
		std::cout << "The array is empty!" << std::endl;
		return;
	}
	num--;
}

template <typename T> unsigned Array<T>::GetNum() const { return num; }
template <typename T> unsigned Array<T>::GetCapacity() const {
	return capacity;
}
