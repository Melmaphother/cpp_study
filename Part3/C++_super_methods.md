## move

> C++中的左值：表达式结束后依然存在的持久对象(代表一个在内存中占有确定位置的对象)
>
> C++中的右值：表达式结束时不再存在的临时对象(不在内存中占有确定位置的表达式）
>
> 只有左值才能被取地址，右值无法被取地址。



```cpp
// FUNCTION TEMPLATE move
template <class _Ty>
_NODISCARD constexpr remove_reference_t<_Ty>&& move(_Ty&& _Arg) noexcept { // forward _Arg as movable
    return static_cast<remove_reference_t<_Ty>&&>(_Arg);
}
```

`std::move`的作用：

- `std::move`作用主要可以将一个左值转换成右值引用，从而可以调用C++11右值引用的拷贝构造函数。

- `std::move`应该是针对你的对象中有在堆上分配内存这种情况而设置的
- 传递的是左值，推导为左值引用，仍旧`static_cast`转换为右值引用。
- 传递的是右值，推导为右值引用，仍旧`static_cast`转换为右值引用。
- 在返回处，直接范围右值引用类型即可。还是通过`renive_reference`获得`_Tp`类型，然后直接`type&&`即可。

`std::move`的意义：

- 在`STL`和自定义类中**实现移动语义，避免拷贝，从而提升程序性能**

  >左值引用一般用的很不爽，因为存在`const`修饰的问题。**右值引用的出现解决了这个问题**，在`STL`的很多容器中，都实现了以**右值引用为参数**的`移动构造函数`和`移动赋值重载函数`，或者其他函数，最常见的如std::vector的`push_back`和`emplace_back`。参数为左值引用意味着拷贝，为右值引用意味着移动

  注意：除非设计不允许移动，`STL`类大都支持移动语义函数，即`可移动的`。 另外，编译器会**默认**在用户自定义的`class`和`struct`中生成移动语义函数，但前提是用户没有主动定义该类的`拷贝构造`函数。

- 可移动对象在**需要拷贝且被拷贝者之后不再被需要**的场景，建议使用`std::move`触发移动语义，提升性能。

- 还有些`STL`类是`move-only`的，比如`unique_ptr`，这种类只有移动构造函数，因此只能移动(转移内部对象所有权，或者叫浅拷贝)，不能拷贝(深拷贝)。

- 还有关于右值引用、万能引用、完美转发、引用折叠的问题，暂时不讨论。

## auto

`auto`可以在声明变量时根据变量初始值的类型自动为此变量选择匹配的类型。

`auto`关键字更适用于类型冗长复杂、变量使用范围专一时，使程序更清晰易读，在简单的变量类型中，应尽量避免使用`auto`。

`auto`只是一个占位符，不能用于类型转换或其他一些操作，如`sizeof`和`typeid`。

## unique_ptr 和 make_unique

**`unique_ptr`** 是 **C++ 11** 提供的用于防止内存泄漏的智能指针中的一种实现，在 `<memory>` 头文件中，独享被管理对象指针所有权的智能指针。`unique_ptr`对象包装一个原始指针，并负责其生命周期。当该对象被销毁时，会在其析构函数中删除关联的原始指针。

注意：

- `unique_ptr`没有copy构造函数，不支持普通的拷贝和赋值操作。仅支持移动构造和移动赋值操作

- `unique_ptr`不支持拷贝操作，但却有一个例外：可以从函数中返回一个`unique_ptr`。

`unique_ptr`的使用场景：

```cpp
void Func()
{
    int *p = new int(5);

    // ...（可能会抛出异常）

    delete p;
}
```

这是我们传统的写法：当我们动态申请内存后，有可能我们接下来的代码由于抛出异常或者提前退出（if语句）而没有执行`delete`操作。

解决的方法是使用`unique_ptr`来管理动态内存，只要`unique_ptr`指针创建成功，其析构函数都会被调用。确保动态资源被释放。

```cpp
void Func()
{
    unique_ptr<int> p(new int(5));

    // ...（可能会抛出异常）
}
```



## inline

在 `c/c++` 中，为了解决一些频繁调用的小函数大量消耗栈空间（栈内存）的问题，特别的引入了 `inline` 修饰符，表示为内联函数。

栈空间就是指放置程序的局部数据（也就是函数内数据）的内存空间。

例如：

```c
inline const char *num_check(int v)
{
    return (v % 2 > 0) ? "奇" : "偶";
}
 
int main(void)
{
    int i;
    for (i = 0; i < 100; i++)
        printf("%02d   %s\n", i, num_check(i));
    return 0;
}
```

`inline`的使用是有限制的：

- `inline` 只适合函数体内代码简单的函数使用，不能包含复杂的结构控制语句例如` while、switch`

- 内联函数本身不能是直接递归函数。

- `inline` 函数仅仅是一个对编译器的建议，所以最后能否真正内联，看编译器的意思。

- 关键字 `inline` 必须与函数定义体放在一起才能使函数成为内联，仅将 `inline` 放在函数声明前面不起任何作用。

  没用：

  ```cpp
  inline void Foo(int x, int y); // inline 仅与函数声明放在一起
  void Foo(int x, int y){}
  ```

  有用：

  ```cpp
  void Foo(int x, int y); // inline 仅与函数声明放在一起
  inline void Foo(int x, int y){}
  ```


## explicit

注意：

- **C++中的explicit关键字只能用于修饰只有一个参数的类构造函数, 它的作用是表明该构造函数是显示的, 而非隐式的**

- **跟它相对应的另一个关键字是implicit, 意思是隐藏的,类构造函数默认情况下即声明为implicit(隐式).**

例如：

```cpp
class CxString  // 没有使用explicit关键字的类声明, 即默认为隐式声明  
{  
public:  
    char *_pstr;  
    int _size;  
    CxString(int size)  
    {  
        _size = size;                // string的预设大小  
        _pstr = malloc(size + 1);    // 分配string的内存  
        memset(_pstr, 0, size + 1);  
    }  
    CxString(const char *p)  
    {  
        int size = strlen(p);  
        _pstr = malloc(size + 1);    // 分配string的内存  
        strcpy(_pstr, p);            // 复制字符串  
        _size = strlen(_pstr);  
    }  
};  
```

调用时：

```cpp
 	CxString string1(24);     // 这样是OK的, 为CxString预分配24字节的大小的内存  
    CxString string2 = 10;    // 这样是OK的, 为CxString预分配10字节的大小的内存  
    CxString string3;         // 这样是不行的, 因为没有默认构造函数, 错误为: “CxString”: 没有合适的默认构造函数可用  
    CxString string4("aaaa"); // 这样是OK的  
    CxString string5 = "bbb"; // 这样也是OK的, 调用的是CxString(const char *p)  
    CxString string6 = 'c';   // 这样也是OK的, 其实调用的是CxString(int size), 且size等于'c'的ascii码  
    string1 = 2;              // 这样也是OK的, 为CxString预分配2字节的大小的内存  
    string2 = 3;              // 这样也是OK的, 为CxString预分配3字节的大小的内存  
    string3 = string1;        // 这样也是OK的, 至少编译是没问题的, 但是如果析构函数里用free释放_pstr内存指针的时候可能会报错, 完整的代码必须重载运算符"=", 并在其中处理内存释放(深拷贝问题)
```

上面的代码中，`CxString string2 = 10;` 这句为什么是可以的呢？在C++中, 如果的构造函数只有一个参数时, 那么在编译的时候就会有一个缺省的转换操作:将该构造函数对应数据类型的数据转换为该类对象. 也就是说 `CxString string2 =10;` 这段代码, 编译器自动将整型转换为`CxString`类对象, 实际上等同于下面的操作：

```cpp
CxString string2(10);  
CxString temp(10);  
CxString string2 = temp;  
```

但是, 上面的代码中的`_size`代表的是字符串内存分配的大小, 那么调用的第二句 `CxString string2 = 10;` 和第六句 `CxString string6 = ‘c’;` 就显得不伦不类, 而且容易让人疑惑。这时就可以用`explicit`关键字禁止隐式转换。



将代码修改为：

```cpp
class CxString  // 使用关键字explicit的类声明, 显示转换  
{  
public:  
    char *_pstr;  
    int _size;  
    explicit CxString(int size)  
    {  
        _size = size;  
        // 代码同上, 省略...  
    }  
    CxString(const char *p)  
    {  
        // 代码同上, 省略...  
    }  
};  
```

调用：

```cpp
    CxString string1(24);     // 这样是OK的  
    CxString string2 = 10;    // 这样是不行的, 因为explicit关键字取消了隐式转换  
    CxString string3;         // 这样是不行的, 因为没有默认构造函数  
    CxString string4("aaaa"); // 这样是OK的  
    CxString string5 = "bbb"; // 这样也是OK的, 调用的是CxString(const char *p)  
    CxString string6 = 'c';   // 这样是不行的, 其实调用的是CxString(int size), 且size等于'c'的ascii码, 但explicit关键字取消了隐式转换  
    string1 = 2;              // 这样也是不行的, 因为取消了隐式转换  
    string2 = 3;              // 这样也是不行的, 因为取消了隐式转换  
    string3 = string1;        // 这样也是不行的, 因为取消了隐式转换, 除非类实现操作符"="的重载  
```

- **explicit关键字的作用就是防止类构造函数的隐式自动转换.**

- **explicit关键字只对有一个参数的类构造函数有效, 如果类构造函数参数大于或等于两个时, 是不会产生隐式转换的,所以explicit关键字也就无效了**.
- **有一个例外, 就是当除了第一个参数以外的其他参数都有默认值的时候, explicit关键字依然有效**, **此时,** **当调用构造函数时只传入一个参数, 等效于只有一个参数的类构造函数**

## override

作用：在成员函数声明或定义中， override 确保该函数为**虚函数**并**覆写来自基类的虚函数**。

位置：函数调用运算符之后，函数体或纯虚函数**标识 “= 0” 之前**。

好处:

- 可以当注释用,方便阅读

- 告诉阅读你代码的人，这是方法的复写

- 编译器可以给你验证 override 对应的方法名是否是你父类中所有的，如果没有则报错．

举例：

```cpp
class base
{
public:
    virtual void fun1(void)=0;
};

class derived : public base
{
public:
#if 1 //OK
    void fun1(void) override {
        cout << "a fun1" << std::endl;
    }
#else // err
    void fun2(void) override {
        cout << "a fun1" << std::endl;
    }
#endif

private:
    /* data */
};
```

**在重写方法时，最好加上这个 override 这个关键字 以 加强代码规范。**

## nullptr和NULL的区别和联系

在C语言和C++中 NULL 是一种宏定义，但两者有所不同：

在C语言中：

```c
 #define NULL ((void*)0)
```

在C++中“

```cpp
#define NULL 0
```

NULL常常有二义性，比如：

```cpp
void test(void *p)
{
    cout<<"p is pointer "<<p<<endl;
 }
void test(int num)
{
    cout<<"num is int "<<num<<endl; 
}
int main(void)
{
    test(NULL);
    return 0; 
}
```

那么NULL会被解释成常量或者指针，导致编译器报错。在C++11中引入了`nullptr`表示空指针。

## C++的四种强制类型转换

#### C风格的强制类型转换

在C++基本的数据类型中，可以分为四类：整型，浮点型，字符型，布尔型。其中数值型包括 整型与浮点型；字符型即为char。

（1）将浮点型数据赋值给整型变量时，**舍弃**其小数部分。
（2）将整型数据赋值给浮点型变量时，数值不变，但是以指数形式存储。
（3）将double型数据赋值给float型变量时，注意数值范围溢出。
（4）字符型数据可以赋值给整型变量，此时存入的是字符的ASCII码。
（5）将一个int，short或long型数据赋值给一个char型变量，只将低8位原封不动的送到char型变量中。 
（6）将有符号型数据赋值给长度相同的无符号型变量，连同原来的符号位一起传送。

在C++语言中新增了四个关键字`static_cast`、`const_cast`、`reinterpret_cast`和`dynamic_cast`。这四个关键字都是用于强制类型转换的。

#### static_cast

**用法：static_cast <direction type_id> (origin expression)**

```cpp
int a = 10;
int b = 6;
double = static_cast<double>(a)/static_cast<double>(b);
```

**static_cast主要有如下几种用法：**

- 用于类层次结构中**基类**和**派生类**之间指针或引用的转换。

  - 进行上行转换（把派生类的指针或引用转换成基类表示）是安全的

  - 进行下行转换（把基类的指针或引用转换为派生类表示），由于没有动态类型检查，所以是不安全的

- **可以实现C++中内置基本数据类型之间的相互转换**，如把int转换成char。这种转换的安全也要开发人员来保证
- 把空指针转换成目标类型的空指针
- 把任何类型的表达式转换为void类型



#### const_cast

**用法：const_cast <'origin' type_id> ('origin' expression)**

> const限定符通常被用来限定变量，用于表示该变量的值不能被修改。

**而const_cast则正是用于强制去掉这种不能被修改的常数特性，但需要特别注意的是const_cast不是用于去除变量的常量性，而是去除指向常数对象的指针或引用的常量性，其去除常量性的对象必须为指针或引用。**

除了`const` 或`volatile`修饰之外， `type_id`和`expression`的类型是一样的。

> `volatile` 是一个关键字，用于声明一个变量是“易变”的，它告诉编译器不要对该变量进行优化，因为它的值可能会在程序的控制之外被改变。

**const_cast主要有如下几种用法：**

- 常量指针被转化成非常量指针，并且仍然指向原来的对象
- 常量引用被转换成非常量引用，并且仍然指向原来的对象；常量对象被转换成非常量对象。

错误用法：

```cpp
const int a = 10;
const int * p = &a;
*p = 20;                  //compile error, pointer decorated with const cann't be modified
int b = const_cast<int>(a);  //compile error, const_cast can only transfer the pointer or citation
```

**使用const_cast通常是一种无奈之举，同时建议C++程序设计过程中一定不要利用const_cast去掉指针或引用的常量性并且去修改原始变量的数值，这是一种非常不好的行为。**



#### reinterpret_cast

**用法：reinterpret_cast<type_id> (expression)**

`type-id`必须是一个指针、引用、算术类型、函数指针或者成员指针。
它可以把一个指针转换成一个整数，也可以把一个整数转换成一个指针（先把一个指针转换成一个整数，在把该整数转换成原类型的指针，还可以得到原先的指针值）。

 **在使用reinterpret_cast强制转换过程仅仅只是比特位的拷贝，因此在使用过程中需要特别谨慎！**

**reinterpret_cast主要有如下几种用法：**

- 改变指针或引用的类型

- 将指针或引用转换为一个足够长度的整形

- 将整型转换为指针或引用类型

```cpp
int *a = new int;
double *d = reinterpret_cast<double *>(a);
```



#### dynamic_cast

**用法：dynamic_cast<type_id> (expression)**

注意：

- 上面三种都是编译时完成的，`dynamic_cast`是运行时完成的，运行中完成类型检查。

- 不能用于内置的基本数据类型的强制转换。

- `dynamic_cast`转换如果成功的话返回的是指向类的指针或引用，转换失败的话则会返回`NULL`。

- 使用`dynamic_cast`进行转换的，基类中一定要有虚函数，否则编译不通过。

  > 基类中需要检测有虚函数的原因：类中存在虚函数，就说明它有想要让基类指针或引用指向派生类对象的情况，此时转换才有意义。这是由于运行时类型检查需要运行时类型信息，而这个信息存储在类的虚函数表中。
  >
  > 只有定义了虚函数的类才有虚函数表。
  
- 在类的转换时，在类层次间进行上行转换时，`dynamic_cast`和`static_cast`的效果是一样的。在进行下行转换时，`dynamic_cast`具有类型检查的功能，比`static_cast`更安全。

  - 向上转换，即为子类指针指向父类指针（一般不会出问题）；向下转换，即将父类指针转化子类指针。

  - 向下转换的成功与否还与将要转换的类型有关，即要转换的指针指向的对象的实际类型与转换以后的对象类型一定要相同，否则转换失败。
  
    >  **在C++中，编译期的类型转换有可能会在运行时出现错误，特别是涉及到类对象的指针或引用操作时，更容易产生错误。`dynamic_cast`操作符则可以在运行期对可能产生问题的类型转换进行测试**

## exit()函数

必须包含头文件 `<cstdlib>`

以下是一些常见的退出代码及其含义：

- **0（或`EXIT_SUCCESS`）**：表示程序正常终止，没有发生错误。这是默认的退出状态码，通常表示成功执行。

- **非零值（通常为`EXIT_FAILURE`（ 1 ）或其他整数）**：表示程序以某种方式失败或出现错误。具体的非零值通常由程序员根据需要选择，以指示不同类型的错误。

## RAII编程思想

RAII（Resource Acquisition Is Initialization）是一种编程思想，通常用于C++等编程语言中，旨在管理资源的生命周期和释放。它的核心思想是：资源的获取应该在对象的构造函数中完成，而资源的释放应该在对象的析构函数中完成。这样可以确保资源在对象生命周期结束时被正确释放，从而避免资源泄漏和内存泄漏等问题。

RAII的主要原则包括以下几点：

- 资源获取：资源（如内存、文件句柄、数据库连接等）应该在对象的构造函数中进行获取。这意味着在创建对象时，资源应该被分配和初始化。

- 资源释放：资源的释放应该在对象的析构函数中进行。当对象的生命周期结束时（例如，对象离开作用域或被显式删除），析构函数会自动调用，从而释放对象持有的资源。

- 自动管理：RAII的一个关键特点是资源管理的自动化。程序员不需要手动调用资源的分配和释放函数，而是依赖对象的生命周期来管理资源。

- 异常安全性：RAII还提供了异常安全性，因为如果在资源分配后发生异常，对象的析构函数会自动释放资源，而不会导致资源泄漏。

RAII的一个常见示例是使用智能指针（如`std::shared_ptr`和`std::unique_ptr`）来管理动态分配的内存。这些智能指针在构造时分配内存，在析构时释放内存，从而避免了内存泄漏问题。

总的来说，RAII是一种强大的编程模式，可以确保资源的正确管理，提高代码的可维护性和可靠性。它广泛应用于C++和其他支持对象生命周期管理的编程语言中。


## 输入输出
C语言的 sscanf 和 sprintf
对应着C++的 istringstream 和 ostringstream