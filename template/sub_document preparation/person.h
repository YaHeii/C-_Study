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