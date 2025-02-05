#pragma once//放置文件重复包含
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "worker_manager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#define FILENAME "empFile.txt"
class WorkerManager
{
public:
    WorkerManager();
    //展示菜单函数
    void showMenu();
    //退出函数
    void exitSystem();
    //记录职工人数
    int m_EmpNum;
    //职工数组指针
    worker ** m_EmpArray;//二级指针，指向职工指针的指针
    //添加职工
    void addEmp();
    //保存文件
    void save();
    //标志文件是否为空
    bool m_FileIsEmpty;
    //统计人数
    int getEmpNum();
    //查找编号
    int isExist(int id);
    //初始化员工
    void initEmp();
    //显示职工
    void showEmp();
    //删除职工
    void delEmp();
    //修改职工
    void modEmp();
    //查找职工
    void findEmp();
    //排序职工
    void sortEmp();
    //清空文件
    void cleanFile();
    ~WorkerManager();
};