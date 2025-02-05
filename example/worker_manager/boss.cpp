#include "boss.h"
#include <iostream>
#include <string>
    boss::boss(int id, string name, int num)
    {
        this->m_id = id;
        this->m_name = name;
        this->m_num = num;
    }
//显示个人信息
    void boss::showInfo()
    {
        cout<<"职工编号"<<this->m_id;
        cout<<"\t职工姓名" << this->m_name;
        cout<<"\t岗位编号" << this->m_num;
        cout<<"\t岗位" << this->getPost();
        cout<<"\t岗位职责：管理公司所有食物"<<endl;
    }
//获取岗位名称
    string boss::getPost()
    {
        return string("老板");
    }