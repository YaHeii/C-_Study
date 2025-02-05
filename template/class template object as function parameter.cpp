#include<iostream>
#include<string>
using namespace std;
//类模板对象作为函数参数
template <class NameType,class AgeType>
//1.指定传入的类型
//2.参数模板化
//3.整个类模板化
class Person
{
public:
    Person(NameType name,AgeType age)
    {
        this->m_name = name;
        this->m_age = age;
    }
    void showPerson()
    {
        cout<<"姓名是"<<this->m_name<<" 年龄是"<<this->m_age<<endl;
    }
    NameType m_name;
    AgeType m_age;

};
void printPerson( Person<string,int>&p)//指定传入类型,最常用
{
    p.showPerson();
}

// template <class NameType,class AgeType>
// void printPerson2( Person<NameType,AgeType>&p)//参数模板化
// {
//     p.showPerson();
//     cout<<"NameType的类型为："<<typeid(NameType).name()<<endl;
//     cout<<"AgeType的类型为："<<typeid(AgeType).name()<<endl;
// }

// template <class T>
// void printPerson3( T &p)//整个类模板化
// {
//     p.showPerson();
//     cout<<"T的类型为："<<typeid(T).name()<<endl;
// }

int main(){
    Person<string,int>p1("孙悟空",999);
    printPerson(p1);
    system("pause");
    return 0;
}