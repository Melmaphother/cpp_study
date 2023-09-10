/***顺序栈的实现***/
#include <iostream>
using namespace std;
// 顺序栈定义
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100 // 顺序栈存储空间的初始分配量
typedef int Status;

template <class SElemType> class Sqstack {
private:
	SElemType *base; // 栈底指针
	SElemType *top;	 // 栈顶指针
	int		   stacksize;

public:
	Sqstack();
	~Sqstack();
	Status	  Popstack();
	Status	  Push(SElemType e);
	int		  getlength();
	SElemType GetTop();
};

template <class SElemType> // 取栈顶元素
SElemType Sqstack<SElemType>::GetTop() {
	return *top;
}

template <class SElemType> Sqstack<SElemType>::Sqstack() {
	base	  = new SElemType[MAXSIZE];
	top		  = base;
	stacksize = MAXSIZE;
}

template <class SElemType> Sqstack<SElemType>::~Sqstack() {
	if (base) {
		delete[] base;
		stacksize = 0;
	}
}

template <class SElemType> Status Sqstack<SElemType>::Push(SElemType e) {
	if (top - base == stacksize)
		return ERROR;
	else { *top++ = e; }
	return OK;
}

template <class SElemType> Status Sqstack<SElemType>::Popstack() {
	if (base == top) { return ERROR; }
	--top;
	return OK;
}

template <class SElemType> int Sqstack<SElemType>::getlength() {
	return top - base;
}

void Matching() {
	char		  a;
	Sqstack<char> Stack;
	while (cin >> a) {
		if (a == '[' || a == '(') {
			Stack.Push(a);
		} else if (a == ']') {
			if (Stack.GetTop() == '[') {
				Stack.Popstack();
			} else {
				cout << "error";
				break;
			}
		}
	}
}

int main() { Matching(); }
