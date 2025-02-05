#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "worker.h"

class manager:public worker
{
public:
    manager(int id, string name, int num);
//显示个人信息
    virtual void showInfo();
//获取岗位名称
    virtual string getPost();
};