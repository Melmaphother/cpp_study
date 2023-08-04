#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;
/* 函数模板
template<typename T>
T myPrint(T a, T b){
	T c;
	c = a + b;
	return c;
	std::cout << "transfer function template" << std::endl;
}
myPrint<int>(a, b);
myPrint<double>(a, b);
*/

#define PI 3.14

/*
 * public     类内可以访问，类外可以访问
 * private    类内可以访问，类外不可以访问，子类不可以访问父类中的私有内容
 * protected  类内可以访问，类外不可以访问，子类可以访问父类中的保护内容
 */
class Circle {
	// 访问权限
	// 公共权限
public:
	// 类中的属性和行为统称为成员
	// 属性
	// 半径
	int r;
	// 行为
	// 求周长
	double calculateZC() { return 2 * PI * r; }
};

class Person {
public:
	// (无参)构造函数 自动调用并且只会调用一次
	Person() { cout << "Person 构造函数的调用" << endl; }
	// 有参构造函数
	Person(int a) { m_Age = a; }
	// 拷贝构造函数
	Person(const Person &p) { // 必须使用const修饰的引用传递
		m_Age = p.m_Age;
	}
	void   SetName(int name) { m_Name = name; }
	string GetName() { return m_Name; }
	void   SetAge(int age) {
		  if (age < 0 || age > 150) {
			  m_Age = 0;
			  cout << "can not set age" << endl;
			  return;
		  }
		  m_Age = age;
	}

	// 析构函数 对象销毁前自动调用并且只会调用一次
	~Person() { cout << "Person 析构函数的调用" << endl; }
	// 构造和析构不写的话由编译器自动生成

private:
	string m_Name;
	int	   m_Age;
	string m_lover;
};

int main() {
	// 通过圆类 创建一个具体的圆（对象）
	Circle c1;
	c1.r = 10;
	cout << c1.calculateZC() << endl;
	system("pause");
}
