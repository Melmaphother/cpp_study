/**
 * @file inherit.cpp
 * @author Melmaphother (Melmaphother@gmail.com)
 * @brief about inherit in c++
 * @version 0.1
 * @date 2023-07-16
 * 
 * @copyright Copyright (c) Melmaphother
 * 
 */
#include <iostream>
#include <string>
using namespace std;
/*

  �̳е��﷨
*/
// ��ͨʵ��ҳ��
// class Java {
// public:
// 	void header() { cout << "����ͷ��" << endl; }
// 	void left() { cout << "�������" << endl; }
// 	void content() { cout << "Java����" << endl; }
// };
// class Python {
// public:
// 	void header() { cout << "����ͷ��" << endl; }
// 	void left() { cout << "�������" << endl; }
// 	void content() { cout << "Python����" << endl; }
// };
// class CPP {
// public:
// 	void header() { cout << "����ͷ��" << endl; }
// 	void left() { cout << "�������" << endl; }
// 	void content() { cout << "CPP����" << endl; }
// };

// �̳�ʵ��ҳ��
/*
 * �����̳з�ʽ
 * class ���� ���̳з�ʽ ����
 * ���� Ҳ��Ϊ�����ࣨ���ã�
 * ���� Ҳ��Ϊ���ࣨ�����ã�
 */
class BasePage {
public:
	void header() { cout << "����ͷ��" << endl; }
	void left() { cout << "�������" << endl; }
	// ! �����������ּ���
	// void content() { cout << "Java��Python��CPP����" << endl; }
};
// Javaҳ��
class Java : public BasePage {
public:
	void content() { cout << "Java����" << endl; }
};
// Pythonҳ��
class Python : public BasePage {
	void content() { cout << "Python����" << endl; }
};
// CPPҳ��
class CPP : public BasePage {
	void content() { cout << "CPP����" << endl; }
};

void test01() {
	Java ja;
	ja.header();
	ja.left();
	ja.content();
}

/*
 * �̳з�ʽ�������̳У�˽�м̳кͱ����̳�
 *
 * ��Ȼ������private��Ա�������޷����ʣ�����ʵ�Ǳ������������ˣ������޷�����
 * ����ȷʵ����������ӵ�еģ��Ǽ̳�������
 *
 * ���������˳��
 * ���� > ���� > ���� > ����
 */
class Base1 {
public:
	int m_A;

protected:
	int m_B;

private:
	int m_C;
};
// �����̳�
class Son1 : public Base1 {
public:
	void func() {
		m_A = 10; // * �����еĹ���Ȩ���������л��ǹ���Ȩ��
		m_B = 10; // * �����еı���Ȩ���������л��Ǳ���Ȩ��
		// m_C = 10;   // * �����е�˽��Ȩ�����������޷�����
	}
};
class Son2 : protected Base1 {
public:
	void func() {
		m_A = 10; // * �����еĹ���Ȩ���������б�Ϊprotected
		m_B = 10; // * �����еı���Ȩ���������л��Ǳ���Ȩ��
		// m_C = 10;   // * �����е�˽��Ȩ�����������޷�����
	}
};
class Son3 : private Base1 {
public:
	void func() {
		m_A = 10; // * �����еĹ���Ȩ���������б�Ϊprivate
		m_B = 10; // * �����еı���Ȩ���������б�Ϊprivate
		// m_C = 10; // * �����е�˽��Ȩ�����������޷�����
	}
};
class GrandSon3 : public Son3 {
public:
	void func() {
		// * m_A = 10;  �޷�����
	}
};

/*
 * �̳���ͬ����Ա�Ĵ�����ʽ
 */
class Base2 {
public:
	Base2() { m_A = 100; }
	void func() { cout << "Base2��������" << endl; }
	void func(int a) { cout << "Base2���غ�������" << endl; }
	int	 m_A;
};
class Son4 : public Base2 {
public:
	Son4() { m_A = 200; }
	void func() { cout << "Son4��������" << endl; }
	int	 m_A;
};
void test02() {
	Son4 s4;
	cout << "Son4 m_A = " << s4.m_A << endl; // * �����200
	cout << "Base4 m_A = " << s4.Base2::m_A
		 << endl; // * �����100��Ҫ��Base������
	s4.func();
	// ����ֱ�ӷ��ʸ����б����ص�ͬ�����������������������ͬ�������Ƿ�����
	s4.Base2::func();
	//! s4.func(100); Ҳ�Ǵ��ı���дΪs4.Base2::func(100);
}

/*
 * ��̳��﷨��ʵ�ʲ����ã��������ʸ���Ҫ��������
 */
class Son5 : public Base1, public Base2 {};

/*
 * ���μ̳У�ʵ��Ҳ�����ã�
 ! ������Ҫ�˽�virtual���ε�֪ʶ
 */
class Animal {
	int m_Age;
};
// class Sheep : public Animal {};
// class Tuo : public Animal {};
class Sheep : virtual public Animal {};
class Tuo : virtual public Animal {
}; // ֻ�̳�����ָ�루vbptr����ָ��һ����vbtable����ͨ��ƫ���ҵ���ͬ������
class SheepTuo : public Sheep, public Tuo {}; // ���������ݵ��ظ�
int main() {
	test01();
	system("pause");
}
