#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    Person(){}
	Person(int a, int b) : m_A(a), m_B(b) {}
    Person operator+(Person& p){
        Person tmp;
        tmp.m_A = p.m_A + this->m_A;
        tmp.m_B = p.m_B + this->m_B;
        return tmp;
    }

public:
	int m_A;
	int m_B;
};

Person PersonAddPerson(Person &p1, Person &p2) {
	Person tmp(0, 0);
	tmp.m_A = p1.m_A + p2.m_A;
	tmp.m_B = p2.m_B + p2.m_B;
	return tmp;
}

// operator 直接替换 PersonAddPerson
// Person operator+(Person &p1, Person &p2) {
// 	Person tmp(0, 0);
// 	tmp.m_A = p1.m_A + p2.m_A;
// 	tmp.m_B = p2.m_B + p2.m_B;
// 	return tmp;
// }

void test01() {
	Person p1(10, 10);
	Person p2(10, 10);
    // Person p3 = p1.operator+(p2)
    // 简化为
    // Person p3 = p1 + p2
	Person p3 = p1 + p2;
	cout << p3.m_A << ' ' << p3.m_B << endl;
}
int main(){
    test01();
    return 0;
}