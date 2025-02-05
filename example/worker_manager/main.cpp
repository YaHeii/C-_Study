#include <iostream>
#include "worker_manager.h"
#include <string>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;

int main(){
    WorkerManager wm;
    int choice;

    while(true){
        //system("cls");
        wm.showMenu();
        cout<<"请输入您的选择"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 0:
            wm.exitSystem();//退出系统
            break;
        case 1:
            wm.addEmp();//添加职工
            break;
        case 2:
            wm.showEmp();//显示职工
            break;
        case 3:
            wm.delEmp();//删除职工
            break;
        case 4:
            wm.modEmp();//修改职工
            break;
        case 5:
            wm.findEmp();//查找职工
            break;      
        case 6:
            wm.sortEmp();//排序职工
            break;   
        case 7:
            wm.cleanFile();//清空文档
            break;       
        default:
        system("cls");//清屏
        cout << "无效选项，请重新输入！" << endl;
        break;
        }
    }
    return 0;
 }