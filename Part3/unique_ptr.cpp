#include <iostream>
#include <memory>
using namespace std;

unique_ptr<int> clone(int p) {
	unique_ptr<int> pInt(new int(p));
	return pInt; // 返回unique_ptr
}

int main() {
	// 创建一个unique_ptr实例
	unique_ptr<int> pInt(new int(5));
	// unique_ptr<int> pInt2(pInt);    // 报错
	// unique_ptr<int> pInt3 = pInt;   // 报错
	// unique_ptr<int> pInt4 = new int(5); // 报错
	unique_ptr<int> pInt5 = move(pInt);
	unique_ptr<int> ret	  = clone(3);
    cout << *ret << endl;
}