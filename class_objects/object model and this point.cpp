#include<iostream>
#include<string>
using namespace std;
//成员变量和成员函数是分开存储的
//非静态变量成员是属于类的对象上的
//静态变量、函数，非静态函数成员不属于类的对象上
//this指针指向本体内部变量。
//this指针的本质是指针常量，指针的指向是不可以修改的。
//在成员函数后加const修饰的是this指向，使指针所指的值也不可修改
//加入mutable可使其可修改。
class person
{
    person(int age)
    {
        m_age = age;
    }
    int m_age;
};