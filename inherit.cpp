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
  公共继承方式
  class 子类 ：继承方式 父类
  子类 也称为派生类（常用）
  父类 也称为基类（不常用）
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

// 调用
void test() {
	Java ja;
	ja.header();
	ja.left();
	ja.content();
}

int main() {
	test();
	system("pause");
}