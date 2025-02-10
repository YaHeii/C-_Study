#include <iostream>
#include <string>
using namespace std;
#include "identity.h"
#include "student_teacher_manager.h"
#include "globalFile.h"
#include "fstream"

student::student()
{

}
student::student(int id, string name, int pwd)
{
    this->m_Id = id;
    this->m_name = name;
    this->m_pwd = pwd;
}
//二级界面展示
void student::second_Menu()
{
    cout<<"1.申请预约" << endl;
    cout<<"2.查看自身预约" << endl;
    cout<<"3.查看所有预约" << endl;
    cout<<"4.取消预约" << endl;
    cout<<"0.注销登录" << endl;
    cout << "请输入您的选择" << endl;
    int m_choice;
    cin >> m_choice;
    switch(m_choice)
    {
    case 1:
        apply_order();
        break;
    case 2:
        show_my_order();
        break;
    case 3:
        show_all_order();
        break;
    case 4:
        cancel_order();
        break;
    case 0:
        delete this;
        cout << "注销成功" << endl;
        break;
    default:
        cout << "输入有误，请重新输入" << endl;
        break;
    }

}
//申请预约
void student::apply_order()
{
    manager m;
    m.show_ComputerRoom();
    cout<<"请输入机房编号"<<endl;
    int computerRoomId;
    cin>>computerRoomId;
    cout<<"请输入预约日期"<<endl;
    string date;
    cin>>date;
    cout<<"请输入预约时间(例如12.03)"<<endl;
    string time;
    cin>>time;
    cout<<"预约成功，等待审核"<<endl;
    int state = 0;
    ofstream ofs;
    ofs.open(ORDER_FILE,ios::app);//追加写入
    ofs<<this->m_Id<<" "<<this->m_name<<" "<<computerRoomId<<" "<<date<<" "<<time<<" "<<state<<endl;
    ofs.close();

}
//查看自身预约
void student::show_my_order()
{
    ifstream infile(ORDER_FILE, ios::in);  // 以读取模式打开文件
    if (!infile) {
        cout << "无法打开预约文件！" << endl;
        return;
    }

    int student_id;
    string student_name, room_id, date, time;
    bool found = false;  // 标记是否找到该学生的预约记录

    int state;
    while (infile >> student_id >> student_name >> room_id >> date >> time >> state) {
        if (student_id == this->m_Id) {  // 找到匹配学号的预约记录
            found = true;
            cout << "学号: " << student_id << ", 姓名: " << student_name
                 << ", 机房编号: " << room_id << ", 日期: " << date
                 << ", 时间: " << time <<"，预约状态："<<state<< endl;
        }
    }

    if (!found) {
        cout << "未找到学号为 " << this->m_Id << " 的预约记录。" << endl;
    }

    infile.close();  // 关闭文件
}

//查看所有预约
void student::show_all_order()
{
    ifstream infile(ORDER_FILE, ios::in);  // 以读取模式打开文件
    if (!infile) {
        cout << "无法打开预约文件！" << endl;
        return;
    }
    int student_id;
    string student_name, room_id, date, time;
    int state;
    while (infile >> student_id >> student_name >> room_id >> date >> time>>state) {
            cout << "学号: " << student_id << ", 姓名: " << student_name
                 << ", 机房编号: " << room_id << ", 日期: " << date
                 << ", 时间: " << time << "，预约状态："<<state<<endl;
    }
}
//取消预约
void student::cancel_order()
{
    ifstream infile(ORDER_FILE, ios::in);  // 以读取模式打开文件
    if (!infile) {
        cout << "无法打开预约文件！" << endl;
        return;
    }

    // 用来暂时存储所有不需要删除的记录
    vector<string> records;
    int student_id;
    string student_name, room_id, date, time;

    bool found = false;  // 标记是否找到该学生的预约记录
    int state;
    // 逐行读取文件内容并过滤记录
    while (infile >> student_id >> student_name >> room_id >> date >> time>>state) {
        if (student_id == this->m_Id) {  // 找到匹配学号的预约记录
            found = true;  // 找到后跳过该记录，相当于删除
            cout << "删除成功，已删除预约记录：" 
                 << "学号: " << student_id 
                 << ", 姓名: " << student_name 
                 << ", 机房编号: " << room_id 
                 << ", 日期: " << date 
                 << ", 时间: " << time << "，预约状态："<<endl;
        } else {
            // 如果没有找到该学号，则保留记录
            records.push_back(to_string(student_id) + " " + student_name + " " + room_id + " " + date + " " + time + " " + to_string(state));
        }
    }

    if (!found) {
        cout << "未找到学号为 " << this->m_Id << " 的预约记录。" << endl;
    }

    infile.close();  // 关闭文件

    // 重新写入文件，覆盖原有内容
    ofstream outfile(ORDER_FILE, ios::out | ios::trunc);  // 打开文件以覆盖内容
    if (!outfile) {
        cout << "无法打开文件进行写入！" << endl;
        return;
    }

    // 将保留的记录重新写入文件
    for (const string& record : records) {
        outfile << record << endl;
    }

    outfile.close();  // 关闭文件
}


teacher::teacher()
{

}
teacher::teacher(int teacher_Id, string name, int pwd)
{

}
//二级界面展示
void teacher::second_Menu()
{
    cout<<"1.查看所有预约" << endl;
    cout<<"2.审核预约" << endl;
    cout<<"0.注销" << endl;
    cout << "请输入您的选择" << endl;
    int m_choice;
    cin >> m_choice;
    switch(m_choice)
    {
    case 1:
        show_all_order();
        break;
    case 2:
        valid_order();
        break;
    case 0:
        delete this;
        cout << "注销成功" << endl;
        break;
    default:
        cout << "输入有误，请重新输入" << endl;
        break;
    }
}
//查看所有预约
void teacher::show_all_order()
{
    student stu;
    stu.show_all_order();
}
//审核预约
void teacher::valid_order()
{
    ifstream infile(ORDER_FILE, ios::in);  // 以读取模式打开文件
    if (!infile) {
        cout << "无法打开预约文件！" << endl;
        return;
    }

    // 用来暂时存储所有记录（包括修改后的记录）
    vector<string> records;
    int student_id;
    string student_name, room_id, date, time;
    int state;  // 用来表示审核状态
    student stu;
    stu.show_all_order();
    cout << "请输入学号以修改预约审核状态：";
    int input_id;
    cin >> input_id;  // 输入学号

    bool found = false;  // 标记是否找到该学生的预约记录

    // 逐行读取文件内容并修改状态
    while (infile >> student_id >> student_name >> room_id >> date >> time >> state) {
        if (student_id == input_id && state == 0) {  // 找到匹配学号且状态为0（未通过审核）
            found = true;
            state = 1;  // 修改审核状态为1（已通过审核）
            cout << "学号为 " << input_id << " 的预约记录已通过审核。" << endl;
        }

        // 保留修改后的记录
        records.push_back(to_string(student_id) + " " + student_name + " " + room_id + " " + date + " " + time + " " + to_string(state));
    }

    if (!found) {
        cout << "未找到学号为 " << input_id << " 的未审核预约记录。" << endl;
    }

    infile.close();  // 关闭文件

    // 重新写入文件，覆盖原有内容
    ofstream outfile("ORDER_FILE", ios::out | ios::trunc);  // 打开文件以覆盖内容
    if (!outfile) {
        cout << "无法打开文件进行写入！" << endl;
        return;
    }

    // 将修改后的记录重新写入文件
    for (const string& record : records) {
        outfile << record << endl;
    }

    outfile.close();  // 关闭文件
}


manager::manager()
{

}
manager::manager(string name, int pwd)
{
    this->m_name = name;
    this->m_pwd = pwd;
}
//二级界面展示
void manager::second_Menu()
{
    cout << "欢迎管理员：" << this->m_name << "登录" << endl;
    cout<<"1.添加账号" << endl;
    cout<<"2.查看账号" << endl;
    cout<<"3.查看机房" << endl;
    cout<<"4.清空预约" << endl;
    cout<<"0.注销登录" << endl;
    cout << "请输入您的选择" << endl;
    int m_choice;
    cin >> m_choice;
    switch(m_choice)
    {
    case 1:
        add_Identity();
        break;
    case 2:
        show_Identity();
        break;
    case 3:
        show_ComputerRoom();
        break;
    case 4:
        clean_file();
        break;
    case 0:
        delete this;
        cout << "注销成功" << endl;
        break;
    default:
        cout << "输入有误，请重新输入" << endl;
        break;
    }
}
//添加账号
void manager::add_Identity()
{
    cout<<"添加账号"<<endl;
    cout<<"1.添加学生" << endl;
    cout<<"2.添加老师" << endl;
    int m_choice;
    cin>>m_choice;
    if(m_choice == 1){
        int id;
        string name;
        int pwd;
        cout<<"请输入学号："<<endl;
        cin>>id;
        cout<<"请输入姓名："<<endl;
        cin>>name;
        cout<<"请输入密码："<<endl;
        cin>>pwd;
        ofstream ofs;
        ofs.open(STUDENT_FILE,ios::app);//追加写入
        ofs<<id<<" "<<name<<" "<<pwd<<endl;
        ofs.close();
        return;
    }else{
        int id;
        string name;
        int pwd;
        cout<<"请输入职工号："<<endl;
        cin>>id;
        cout<<"请输入姓名："<<endl;
        cin>>name;
        cout<<"请输入密码："<<endl;
        cin>>pwd;
        ofstream ofs;
        ofs.open(TEACHER_FILE,ios::app);//追加写入
        ofs<<id<<" "<<name<<" "<<pwd<<endl;
        ofs.close();
        return;
    }
}
//查看账号
void manager::show_Identity()
{
    cout<<"请选择查看内容"<<endl;
    cout<<"1.查看所有学生" << endl;
    cout<<"2.查看所有老师" << endl;
    int m_choice;
    cin>>m_choice;
    if(m_choice == 1){
        ifstream ifs;
        ifs.open(STUDENT_FILE,ios::in);
        if(!ifs.is_open())
        {
            cout << "文件打开失败" << endl;
            return;
        }
        int id;
        string name;
        int pwd;
        while(ifs>>id&&ifs>>name&&ifs>>pwd)
        {
            cout<<"学号："<<id<<" 姓名："<<name<<" 密码："<<pwd<<endl;
        }
        ifs.close();
        return;
    }else{
        ifstream ifs;
        ifs.open(TEACHER_FILE,ios::in);
        if(!ifs.is_open())
        {
            cout << "文件打开失败" << endl;
            return;
        }
        int id;
        string name;
        int pwd;
        while(ifs>>id&&ifs>>name&&ifs>>pwd)
        {
            cout<<"职工号："<<id<<" 姓名："<<name<<" 密码："<<pwd<<endl;
        }
        ifs.close();
        return;
    }
    system("pause");
}
//查看机房
void manager::show_ComputerRoom()
{
        //初始化机房信息
    //this->initVector();
    ifstream ifs;
    ifs.open(COMPUTER_FILE, ios::in);
    ComputerRoom computerRoom;
    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    while(ifs>>computerRoom.m_ComputerRoomID>>computerRoom.m_MaxNum)
    {
        this->v_computerRoom.push_back(computerRoom);
    }
    ifs.close();
    cout<<"机房信息初始化成功" << endl;
    cout<<"机房信息如下"<<endl;
    for(int i = 0; i < v_computerRoom.size(); i++)
    {
        cout<<"机房编号："<<v_computerRoom[i].m_ComputerRoomID<<" 机房最大容量："<<v_computerRoom[i].m_MaxNum<<endl;
    }
}
//清空预约
void manager::clean_file()
{
    ifstream ofs(ORDER_FILE,ios::trunc);
    ofs.close();
    cout<<"清空成功" << endl;

}