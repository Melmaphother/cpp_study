## 类和对象

- 面向对象的三大特性：
  封装，继承，多态
- 封装
  - public
  - protected
  - private
    成员属性的私有化，可以自己控制读写权限，检测有效性
    ```cpp
        class Person{
        public:
            void SetName(int name){
                m_Name = name;
            }
            string GetName(){
                return m_Name;
            }
        private: 
            string m_Name;
            int m_Age;
            string m_lover;
        };
    ```
- 继承
- 多态

## 模板
#### 函数模板

#### 类模板
#### STL