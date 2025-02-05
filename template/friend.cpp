#include<iostream>
#include<string>
using namespace std;
//全局函数类内实现，较为简单，建议
//全局函数类外实现较为复杂
//提前让编译器知道这个类的存在
template<class NameType,class AgeType>
class person;

//全局友元函数的类外实现,必须放在前面
template<class NameType, class AgeType>
void showPerson(person<NameType, AgeType> p)
{
    cout << "name: " << p.m_name << " age: " << p.m_age << endl;
}

template<class NameType,class AgeType>
class person
{
public:
    friend void showPerson<>(person<NameType, AgeType> p);//函数模板在全局作用域下声明
                                                        //需要加上模板参数列表
                                                        //如果全局函数类外实现，需要让编译器提前知道这个函数的存在
    person(NameType name,AgeType age)
    {
        this->m_name = name;
        this->m_age = age;
    }
private:
    NameType m_name;
    AgeType m_age;
};

int main()
{
    person<string,int>p1("孙悟空",999);
    showPerson(p1);
    system("pause");
    return 0;
}