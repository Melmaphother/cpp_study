#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;
/* ����ģ��
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
 * public     ���ڿ��Է��ʣ�������Է���
 * private    ���ڿ��Է��ʣ����ⲻ���Է��ʣ����಻���Է��ʸ����е�˽������
 * protected  ���ڿ��Է��ʣ����ⲻ���Է��ʣ�������Է��ʸ����еı�������
 */
class Circle {
	// ����Ȩ��
	// ����Ȩ��
public:
	// ���е����Ժ���Ϊͳ��Ϊ��Ա
	// ����
	// �뾶
	int r;
	// ��Ϊ
	// ���ܳ�
	double calculateZC() { return 2 * PI * r; }
};

class Person {
public:
	// (�޲�)���캯�� �Զ����ò���ֻ�����һ��
	Person() { cout << "Person ���캯���ĵ���" << endl; }
	// �вι��캯��
	Person(int a) { m_Age = a; }
	// �������캯��
	Person(const Person &p) { // ����ʹ��const���ε����ô���
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

	// �������� ��������ǰ�Զ����ò���ֻ�����һ��
	~Person() { cout << "Person ���������ĵ���" << endl; }
	// �����������д�Ļ��ɱ������Զ�����

private:
	string m_Name;
	int	   m_Age;
	string m_lover;
};

int main() {
	// ͨ��Բ�� ����һ�������Բ������
	Circle c1;
	c1.r = 10;
	cout << c1.calculateZC() << endl;
	system("pause");
}
