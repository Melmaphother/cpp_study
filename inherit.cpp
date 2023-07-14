#include <iostream>
#include <string>
using namespace std;
/*

  继承的语法
*/
// 普通实现页面
// class Java {
// public:
// 	void header() { cout << "公共头部" << endl; }
// 	void left() { cout << "公共左侧" << endl; }
// 	void content() { cout << "Java内容" << endl; }
// };
// class Python {
// public:
// 	void header() { cout << "公共头部" << endl; }
// 	void left() { cout << "公共左侧" << endl; }
// 	void content() { cout << "Python内容" << endl; }
// };
// class CPP {
// public:
// 	void header() { cout << "公共头部" << endl; }
// 	void left() { cout << "公共左侧" << endl; }
// 	void content() { cout << "CPP内容" << endl; }
// };

// 继承实现页面
/*
 * 公共继承方式
 * class 子类 ：继承方式 父类
 * 子类 也称为派生类（常用）
 * 父类 也称为基类（不常用）
 */
class BasePage {
public:
	void header() { cout << "公共头部" << endl; }
	void left() { cout << "公共左侧" << endl; }
	// ! 保留公共部分即可
	// void content() { cout << "Java、Python、CPP内容" << endl; }
};
// Java页面
class Java : public BasePage {
public:
	void content() { cout << "Java内容" << endl; }
};
// Python页面
class Python : public BasePage {
	void content() { cout << "Python内容" << endl; }
};
// CPP页面
class CPP : public BasePage {
	void content() { cout << "CPP内容" << endl; }
};

void test01() {
	Java ja;
	ja.header();
	ja.left();
	ja.content();
}

/*
 * 继承方式：公共继承，私有继承和保护继承
 *
 * 虽然父类中private成员中子类无法访问，但其实是被编译器隐藏了，所以无法访问
 * 但是确实在子类中是拥有的，是继承下来的
 *
 * 构造和析构顺序
 * 父构 > 子类 > 子析 > 父析
 */
class Base1 {
public:
	int m_A;

protected:
	int m_B;

private:
	int m_C;
};
// 公共继承
class Son1 : public Base1 {
public:
	void func() {
		m_A = 10; // * 父类中的公共权限在子类中还是公共权限
		m_B = 10; // * 父类中的保护权限在子类中还是保护权限
		// m_C = 10;   // * 父类中的私有权限在子类中无法访问
	}
};
class Son2 : protected Base1 {
public:
	void func() {
		m_A = 10; // * 父类中的公共权限在子类中变为protected
		m_B = 10; // * 父类中的保护权限在子类中还是保护权限
		// m_C = 10;   // * 父类中的私有权限在子类中无法访问
	}
};
class Son3 : private Base1 {
public:
	void func() {
		m_A = 10; // * 父类中的公共权限在子类中变为private
		m_B = 10; // * 父类中的保护权限在子类中变为private
		// m_C = 10; // * 父类中的私有权限在子类中无法访问
	}
};
class GrandSon3 : public Son3 {
public:
	void func() {
		// * m_A = 10;  无法访问
	}
};

/*
 * 继承中同名成员的处理方式
 */
class Base2 {
public:
	Base2() { m_A = 100; }
	void func() { cout << "Base2函数调用" << endl; }
	void func(int a) { cout << "Base2重载函数调用" << endl; }
	int	 m_A;
};
class Son4 : public Base2 {
public:
	Son4() { m_A = 200; }
	void func() { cout << "Son4函数调用" << endl; }
	int	 m_A;
};
void test02() {
	Son4 s4;
	cout << "Son4 m_A = " << s4.m_A << endl; // * 输出的200
	cout << "Base4 m_A = " << s4.Base2::m_A
		 << endl; // * 输出的100，要加Base作用域
	s4.func();
	// 不能直接访问父类中被隐藏的同名函数，必须加作用域，无论同名函数是否重载
	s4.Base2::func();
	//! s4.func(100); 也是错的必须写为s4.Base2::func(100);
}

/*
 * 多继承语法，实际不常用，重名访问父类要加作用域
 */
class Son5 : public Base1, public Base2 {};

/*
 * 菱形继承，实际也不常用，
 ! 不过需要了解virtual修饰的知识
 */
class Animal {
	int m_Age;
};
// class Sheep : public Animal {};
// class Tuo : public Animal {};
class Sheep : virtual public Animal {};
class Tuo : virtual public Animal {};   // 只继承了虚指针（vbptr），指向一个（vbtable），通过偏移找到共同的数据
class SheepTuo : public Sheep, public Tuo {};   // 避免了数据的重复
int main() {
	test01();
	system("pause");
}



// gitmmnmnmnm