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

class Dog : public Animal {
public:
	void speak() { cout << "С����˵��" << endl; }
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
	Dog dog;
	doSpeak(dog);
}
void test02() {
	cout << "sizeof(Animal) = " << sizeof(Animal) << endl;
	/*
	int *p = NULL;
	int	 a = 0;
	cout << "sizeof(int) = " << sizeof(a) << endl;
	cout << "sizeof(int pointer) = " << sizeof(p) << endl;
	float b = 0;
	float* q = NULL;
	cout << "sizeof(float) = " << sizeof(b) << endl;
	cout << "sizeof(float pointer) = " << sizeof(q) << endl;
	double c = 0;
	double* r = NULL;
	cout << "sizeof(double) = " << sizeof(c) << endl;
	cout << "sizeof(double pointer) = " << sizeof(r) << endl;
	*/
}

int main() {
	test01();
	test02();
	system("pause");
}