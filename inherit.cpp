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
  �����̳з�ʽ
  class ���� ���̳з�ʽ ����
  ���� Ҳ��Ϊ�����ࣨ���ã�
  ���� Ҳ��Ϊ���ࣨ�����ã�
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

// ����
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