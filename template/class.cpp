#include <iostream>
using namespace std;
#include <string>

//类模板
//类模板是类的蓝图，通过类模板可以生成类
//类模板与函数模板的区别
//类模板没有自动类型推导的使用方式
//类模板在模板参数列表中可以有默认参数
template <class NameType, class AgeType>
//template <class NameType, class AgeType = int>可以指定默认模板参数，在声明时即可省略一个参数
//在类模板中创建成员函数，与普通类不同
//成员函数的类外实现时，需要添加模板参数列表
//普通类的成员函数可以一开始就创建
//类模板的成员函数一开始不会创建，只有在调用时才会创建
//所以对象类型不同，调用的成员函数也不同
class Person
{
public:
    Person(NameType name,AgeType age)
    {
        this->m_age = age;
        this->m_name = name;
    }
    void showPerson()
    {
        cout<<"name:"<<this->m_name<<" age:"<<this->m_age<<endl;
    }
    NameType m_name;
    AgeType m_age;
};
int main()
{
    Person<string,int>p1("孙悟空",999);//必须添加类型
    p1.showPerson();
    system("pause");
    return 0;
}
