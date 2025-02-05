#pragma once
#include <iostream>
#include <string>
using namespace std;

class  worker
{
public:
    worker(){}; 
    virtual ~worker(){}; //虚析构函数
//职工编号
    int m_id;
//姓名
    string m_name;
//部门编号
    int m_num;
//显示个人信息
    virtual void showInfo() = 0;
//获取岗位名称
    virtual string getPost() = 0;
};


