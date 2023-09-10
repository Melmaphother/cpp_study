#include <fstream>
#include <string>
#include <iostream>

using namespace std;

void test01()
{
	ifstream ifs;
	ifs.open("test.txt", ios::in);

	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	//第一种方式
    
	char buf[1024] = { 0 };
    int i = 0;
	while (ifs >> buf)
	{
		cout << buf << endl;
        cout << i++ << endl;
	}

	//第二种
	// char buf[1024] = { 0 };
    // int i = 0;
	// while (ifs.getline(buf,sizeof(buf)))
	// {
	// 	cout << buf << endl;
    //     cout << i++ << endl;
	// }

	//第三种
	//string buf;
	//while (getline(ifs, buf))
	//{
	//	cout << buf << endl;
	//}

	// char c;
	// while ((c = ifs.get()) != EOF)
	// {
	// 	cout << c;
	// }

	// ifs.close();


}

int main() {

	test01();

	system("pause");

	return 0;
}