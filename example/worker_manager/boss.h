#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

class boss:public worker
{
public:
   boss(int id, string name, int num);
//显示个人信息
    virtual void showInfo();
//获取岗位名称
    virtual string getPost();
};