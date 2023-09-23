#include <cstdlib>
#include <iostream>
using namespace std;

class Array {
public:
	Array() {}
	Array(Array &&other_array) {
		this->data		 = other_array.data;
		this->size		 = other_array.size;
		other_array.data = nullptr;
	}

public:
	int *data;
	int	 size;
};

void test01() {
	Array a;
	// Array b(a);
	//! 错误，不能使用左值引用，如果要使用左值引用，必须要实现对应的深拷贝构造函数

	Array b = std::move(a);
}

int main() {
    test01();
	// exit(EXIT_SUCCESS);
	// exit(EXIT_FAILURE);
}