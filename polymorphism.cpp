/**
 * @file polymorphism.cpp
 * @author Melmaphother (Melmaphother@gmail.com)
 * @brief about polymorphism in c++
 * @version 0.1
 * @date 2023-07-15
 *
 * @copyright Copyright (c) Melmaphother
 *
 */

#include <iostream>
#include <string>
using namespace std;

/*
 * ��̬��Ϊ����
 * ��̬��̬���������غ�������������ھ�̬��̬�����ú�����-----������ַ��󶨣�����׶�ȷ��������ַ
 ! ��̬��̬����������麯������ʱ��̬------������ַ��󶨣����н׶�ȷ��������ַ
 */
/*
 * ��̬��̬����������
 * - �м̳й�ϵ
 * - ������д������麯��
 * ��̬��̬��ʹ��
 ! �����ָ�������ִ���������
*/
class Animal {
public:
	//* void speak() { cout << "�����˵��" << endl; }
	virtual void speak() { cout << "�����˵��" << endl; }
};

class Cat : public Animal {
public:
	// ! ��д ��������ֵ������ �������� �����б� ��ȫ��ͬ
	// * ������virtual�ؼ��ֿ�д�ɲ�д
	void speak() { cout << "Сè��˵��" << endl; }
};

// * ��ַ��󶨣��ڱ���׶ξ�ȷ���˺�����ַ
// * �������è˵������Ҫ����ַ��󶨣��������н׶ΰ�
// !��Ҫ�������еĺ�������virtual�ؼ���
// !���൱�����غ�����������Ҫ��ͬһ�������²������أ���virtual��������亯������
void doSpeak(Animal &animal) // Animal& animal = cat
{
	animal.speak();
}

void test01() {
	Cat cat;
	// ��ʱ���õ��Ǹ����speak����
	doSpeak(cat);
}
void test02() { cout << "sizeof(Animal) = " << sizeof(Animal) << endl; }

int main() {
	// test01();
	test02();
	system("pause");
}