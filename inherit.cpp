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

/*
 * �̳з�ʽ�������̳У�˽�м̳кͱ����̳�
 */
class Base {
public:
	int m_A;

protected:
	int m_B;

private:
	int m_C;
};
// �����̳�
class Son1 : public Base {
public:
	void func() {
		m_A = 10; // * �����еĹ���Ȩ���������л��ǹ���Ȩ��
		m_B = 10; // * �����еı���Ȩ���������л��Ǳ���Ȩ��
		// m_C = 10;   // * �����е�˽��Ȩ�����������޷�����
	}
};
class Son2 : protected Base {
public:
	void func() {
		m_A = 10; // * �����еĹ���Ȩ���������б�Ϊprotected
		m_B = 10; // * �����еı���Ȩ���������л��Ǳ���Ȩ��
		// m_C = 10;   // * �����е�˽��Ȩ�����������޷�����
	}
};
class Son3 : private Base {
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
// ����
void test01() {
	Java ja;
	ja.header();
	ja.left();
	ja.content();
}

int main() {
	test01();
	system("pause");
}