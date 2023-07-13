#include <iostream>
#include <string>
using namespace std;
/*

  继承的语法
*/
// 普通实现页面
class Java {
public:
	void header() { cout << "公共头部" << endl; }
	void left() { cout << "公共左侧" << endl; }
	void content() { cout << "Java内容" << endl; }
};
class Python {
public:
	void header() { cout << "公共头部" << endl; }
	void left() { cout << "公共左侧" << endl; }
	void content() { cout << "Python内容" << endl; }
};
class CPP {
public:
	void header() { cout << "公共头部" << endl; }
	void left() { cout << "公共左侧" << endl; }
	void content() { cout << "CPP内容" << endl; }
};