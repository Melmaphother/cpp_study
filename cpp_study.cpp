#include <iostream>
#include <Windows.h>
using namespace std;
/* 函数模板
template<typename T>
void myPrint(T a, T b){
    std::cout << "transfer function template" << std::endl;
}
myPrint<int>(a, b);
*/

#define PI 3.14

/*
public     类内可以访问，类外可以访问
private    类内可以访问，类外不可以访问，子类不可以访问父类中的私有内容
protected  类内可以访问，类外不可以访问，子类可以访问父类中的保护内容
*/
class Circle{
    // 访问权限
    // 公共权限
public:
    // 类中的属性和行为统称为成员
    // 属性
    // 半径
    int r;
    // 行为
    // 求周长
    double calculateZC(){
        return 2 * PI * r;
    }

};

int main(){ 
    // 通过圆类 创建一个具体的圆（对象）
    Circle c1;
    c1.r = 10;
    cout << c1.calculateZC()<< endl;
    system("pause");
}
