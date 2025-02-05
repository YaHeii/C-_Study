#pragma once
#include <iostream>
#include <string>
using namespace std;
template<class NameType,class AgeType>
class person
{
public:
    NameType m_name;
    AgeType m_age;
    person(NameType name,AgeType age);
    void showPerson();

};
template<class NameType,class AgeType>
person<NameType,AgeType>::person(NameType name,AgeType age)
{
    this->m_name = name;
    this->m_age = age;
}
template<class NameType,class AgeType>
void person<NameType,AgeType>::showPerson()
{
    cout<<"name:"<<this->m_name<<" age:"<<this->m_age<<endl;
}