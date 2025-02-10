#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "identity.h"
#include "globalFile.h"
#include "student_teacher_manager.h"


//登录全局函数
void login(string FILE_NAME, int choice)
{
    Identity *person = NULL;//定义一个指针
    ifstream ifs;
    ifs.open(FILE_NAME, ios::in);//以只读的方式打开文件
    if(!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }   
    int m_Id;//学号
    int teacher_Id;//工号

    if(choice == 1)
    {
        cout<<"请输入学号：";
        cin>>m_Id;
    }else if(choice == 2)
    {
        cout<<"请输入工号：";
        cin>>teacher_Id;
    }
    cout<<"请输入用户名：";
    string m_name;
    cin>>m_name;
    cout<<"请输入密码：";
    int m_pwd;
    cin>>m_pwd;
    if(choice == 1)
    {
        //学生登陆
        int fid;
        string fName;
        int fPwd;
        while(ifs>>fid&&ifs>>fName&&ifs>>fPwd)
        {
            if(fid == m_Id && fName == m_name && fPwd == m_pwd)
            {
                cout<<"验证成功"<<endl;
                person = new student(m_Id, m_name, m_pwd);
                person->second_Menu();
                return;
            }
        }
    }else if(choice == 2)
    {
        //老师登录
        int fid;
        string fName;
        int fPwd;
        while(ifs>>fid&&ifs>>fName&&ifs>>fPwd)
        {
            if(fid == teacher_Id && fName == m_name && fPwd == m_pwd)
            {
                cout<<"验证成功"<<endl;
                person = new teacher(m_Id, m_name, m_pwd);
                person->second_Menu();
                return;
            }
        }
    }else if(choice == 3){
        //管理员登录
        string fName;
        int fPwd;
        while(ifs>>fName&&ifs>>fPwd)
        {
            if(fName == m_name && fPwd == m_pwd)
            {
                cout<<"验证成功"<<endl;
                person = new manager( m_name, m_pwd);
                person->second_Menu();
                return;
            }
        }
    }
    cout<<"验证失败"<<endl;
    
}

int main()
{
    int choice;
    while(true)
    {
        cout<<"======================  欢迎来到传智播客机房预约系统  ======================" << endl;
        cout<<"请输入您的选择"<<endl;
        cout << "\t\t|          1.学生代表           |\n";
        cout << "\t\t|          2.老师               |\n";
        cout << "\t\t|          3.管理员             |\n";
        cout << "\t\t|          0.退出               |\n";
        cin >>choice;
        switch (choice)
        {
        case 1://学生身份
        login(STUDENT_FILE,1);
            break;
        case 2://老师
        login(TEACHER_FILE,2);
            break;
        case 3://管理员
        login(ADMIN_FILE,3);
            break;
        case 0://退出
        cout << "欢迎下次使用" << endl;
        return 0;
            break;
        default:
            cout << "输入错误，请重新输入" << endl;
            break;
        }
    }
    system("pause");
    return 0; 
}