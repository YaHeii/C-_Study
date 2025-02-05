#include "manager.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
    manager::manager(int id, string name, int num)
    {
        this->m_id = id;
        this->m_name = name;
        this->m_num = num;
    }
//显示个人信息
    void manager::showInfo()
    {
        cout<<"经理编号"<<this->m_id;
        cout<<"\t经理姓名" << this->m_name;
        cout<<"\t经理编号" << this->m_num;
        cout<<"\t岗位" << this->getPost();
        cout<<"\t岗位职责：完成董事长交代任务"<<endl;
    }
//获取岗位名称
    string manager::getPost()
    {
        return string("经理");
    }
    //保存文件
   