#pragma once 
#include <iostream>
#include <string>
using namespace std;
#include "identity.h"
#include"computerRoom.h"
#include "vector"

class student :public Identity
{
public:
    student();
    student(int id, string name, int pwd);
    //二级界面展示
    void second_Menu();
    //申请预约
    void apply_order();
    //查看自身预约
    void show_my_order();
    //查看所有预约
    void show_all_order();
    //取消预约
    void cancel_order();

    int m_Id;//学号
};

class teacher :public Identity//老师类
{
public:
    teacher();
    teacher(int teacher_Id, string name, int pwd);
    //二级界面展示
    void second_Menu();
    //查看所有预约
    void show_all_order();
    //审核预约
    void valid_order();

    int teacher_Id;//老师工号
};

class manager :public Identity//管理员类
{

public:
    manager();
    manager(string name, int pwd);
    //二级界面展示
    void second_Menu();
    //添加账号
    void add_Identity();
    //查看账号
    void show_Identity();
    //查看机房
    void show_ComputerRoom();
    //清空预约
    void clean_file();

    vector<ComputerRoom> v_computerRoom;
};
