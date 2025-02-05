#include "employee.h"
#include <iostream>
#include <string>
    employee::employee(int id, string name, int num)
    {
        this->m_id = id;
        this->m_name = name;
        this->m_num = num;
    }
//显示个人信息
    void employee::showInfo()
    {
        cout<<"职工编号"<<this->m_id;
        cout<<"\t职工姓名" << this->m_name;
        cout<<"\t岗位编号" << this->m_num;
        cout<<"\t岗位" << this->getPost();
        cout<<"\t岗位职责：完成经理交代任务"<<endl;
    }
//获取岗位名称
    string employee::getPost()
    {
        return string("员工");
    }