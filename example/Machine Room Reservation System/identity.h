#pragma once 
#include <iostream>
#include <string>
using namespace std;

class Identity
{
public:
//基类虚函数实现
    virtual void second_Menu() = 0;
    string m_name;//姓名
    int m_pwd;//密码
};