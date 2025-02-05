#include <iostream>
#include <string>
#include <fstream>
#include "worker_manager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;
#define FILENAME "empFile.txt"

WorkerManager::WorkerManager()
{
    //初始化属性
    //1、读文件中的数据
    ifstream ifs;
    ifs.open(FILENAME, ios::in);//打开文件，读文件
    if(!ifs.is_open()){
        cout<<"文件不存在"<<endl;
        //初始化属性
        //初始化职工人数
        this->m_EmpNum = 0;
        //初始化职工数组指针
        this->m_EmpArray = NULL;
        //初始化文件是否为空
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    //文件存在，并且文件为空
    char ch;
    ifs >> ch;
    if(ifs.eof()){//文件为空
        cout<<"文件为空"<<endl;
        //初始化属性
        //初始化职工人数
        this->m_EmpNum = 0;
        //初始化职工数组指针
        this->m_EmpArray = NULL;
        //初始化文件是否为空
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    //文件存在，并且文件不为空
    int num = this->getEmpNum();
    cout<<"职工人数为："<<num<<endl;
    this->m_EmpNum = num;

    //开辟空间
    this->m_EmpArray = new worker * [this->m_EmpNum];
    this->initEmp();
//     //测试代码
    // for(int i=0;i<this->m_EmpNum;i++)
    // {
    //     cout<<"职工编号："<<this->m_EmpArray[i]->m_id<<" "
    //         <<"姓名："<<this->m_EmpArray[i]->m_name<<""
    //         <<"岗位："<<this->m_EmpArray[i]->m_num<<endl;
    // }
}
WorkerManager::~WorkerManager()
{

}
void WorkerManager::showMenu()
{
    cout << "********************************************" << endl;
    cout << "************** 0.退出管理系统 **************" << endl;
    cout << "************** 1.增加职工信息 **************" << endl;
    cout << "************** 2.显示职工信息 **************" << endl;
    cout << "************** 3.删除离职职工 **************" << endl;
    cout << "************** 4.修改职工信息 **************" << endl;
    cout << "************** 5.查找职工信息 **************" << endl;
    cout << "************** 6.按照编号排序 **************" << endl;
    cout << "************** 7.清空所有文档 **************" << endl;
    cout << "********************************************" << endl;
    cout<<endl;
}
void WorkerManager::exitSystem()
{
    cout<<"欢迎下次使用"<<endl;
    system("pause");
    exit(0);//退出程序
}
void WorkerManager::addEmp()
{
    cout<<"请输入添加职工数量"<<endl;
    int addNum = 0;
    cin>>addNum;
    if(addNum>0){
        //添加
        //计算添加新空间大小
        int newSize = this->m_EmpNum + addNum;
        //开辟新空间
        worker ** newSpace = new worker*[newSize];
        //将原来空间下数据存放到新空间下
        if(this->m_EmpArray != NULL){
            for(int i = 0; i < this->m_EmpNum; i++){
                newSpace[i] = this->m_EmpArray[i];
            }
        }
        for( int i = 0;i<addNum; i++){
            int id;
            string name;
            int num;
            int dSelect;
            cout<<"请输入第"<<i+1<<"个新职工编号"<<endl;
            cin>>id;
            cout<<"请输入第"<<i+1<<"个新职工姓名"<<endl;
            cin>>name;
            cout<<"请输入第"<<i+1<<"岗位"<<endl;
            cin>>num;
            cout<<"请选择该职工岗位"<<endl;
            cout<<"1、普通职工"<<endl;
            cout<<"2、经理"<<endl;
            cout<<"3、老板"<<endl;
            cin>>dSelect;
            worker * worker = NULL;//根据选择创建不同职工对象
            switch (dSelect)
            {
            case 1:
                worker = new employee(id,name,num);
                break;
            case 2:
                worker = new manager(id,name,num);
                break;
            case 3:
                worker = new boss(id,name,num);
                break;
            default:
                break;
            }
            newSpace[this->m_EmpNum+i] = worker;//将创建职工职工放入数组中，避免数据重叠
        }
    delete [] this->m_EmpArray;//释放原有空间
    this->m_EmpArray = newSpace;//更改新空间的指向
    this->m_EmpNum = newSize;//更新新的职工人数
    cout<<"添加成功"<<endl;
    this->save();//保存数据到文件中
    this->m_FileIsEmpty = false;//更新文件状态
    }else{
        cout<<"输入数据有误"<<endl;
    }

}
 void WorkerManager::save()
    {
        ofstream ofs;
        ofs.open(FILENAME, ios::out);//用输出的方式打开文件，写文件
        //将每个人数据写入到文件中
        for(int i = 0; i < this->m_EmpNum; i++){
            ofs << this->m_EmpArray[i]->m_id << " "
                << this->m_EmpArray[i]->m_name << " "
                << this->m_EmpArray[i]->m_num << endl;
        }
        //关闭文件
        ofs.close();
    }
    int WorkerManager::getEmpNum()
    {
        this->m_EmpNum = 0;
        //初始化职工数组指针
        this->m_EmpArray = NULL;
        //初始化文件是否为空
        this->m_FileIsEmpty = false;
        ifstream ifs;
        ifs.open(FILENAME, ios::in);//打开文件，读文件
        int id;
        string name;
        int num;
        while(ifs >> id && ifs >> name && ifs >> num){
            //统计人数变量
            this->m_EmpNum++;
        }
        ifs.close();
        return this->m_EmpNum;
    }
    void WorkerManager::initEmp()
    {
        ifstream ifs;
        ifs.open(FILENAME, ios::in);//打开文件，读文件
        int id;
        string name;
        int num;
        int index = 0;
        while(ifs>>id && ifs>>name && ifs>>num){
            worker * worker = NULL;
            if(num == 1){
                worker = new employee(id,name,num);
            }else if(num == 2){
                worker = new manager(id,name,num);
            }else{
                worker = new boss(id,name,num);
            }
            this->m_EmpArray[index] = worker;
            index++;
        }
        ifs.close();
    }
    void WorkerManager::showEmp()
    {
        if(this->m_FileIsEmpty){
            cout<<"文件不存在或记录为空"<<endl;
        }else{
            for(int i = 0; i < this->m_EmpNum; i++){
                this->m_EmpArray[i]->showInfo();
            }
        }
    }
    void WorkerManager::delEmp()
    {
        if(this->m_FileIsEmpty){
            cout<<"文件不存在或记录为空"<<endl;
        }else{
            //按照职工编号删除
            cout<<"请输入想要删除的职工编号"<<endl;
            int id = 0;
            cin>>id;
            int index = -1;
            //遍历查找要删除的职工
            for(int i = 0; i < this->m_EmpNum; i++){
                if(this->m_EmpArray[i]->m_id == id){
                    index = i;
                    break;
                }
            }
            //删除职工
            if(index != -1){
                for(int i = index; i < this->m_EmpNum-1; i++){//数据前移覆盖
                    this->m_EmpArray[i] = this->m_EmpArray[i+1];
                }
                this->m_EmpNum--;
                this->save();
                cout<<"删除成功"<<endl;
            }else{
                cout<<"删除失败，未找到该职工"<<endl;
            }
        }
    }
    int WorkerManager::isExist(int id)
    {
        int index = -1;
        for(int i = 0; i < this->m_EmpNum; i++){
            if(this->m_EmpArray[i]->m_id == id){
                index = i;
                break;
            }
        }
        return index;
    }
    void WorkerManager::modEmp()
    {
        if(this->m_FileIsEmpty){
            cout<<"文件不存在或记录为空"<<endl;
        }else{
            cout<<"请输入修改职工的编号"<<endl;
            int id;
            cin>>id;
            int index = this->isExist(id);
            if(index != -1){
                delete this->m_EmpArray[index];
                int newId = 0;
                string newName = "";
                int newNum = 0;
                cout<<"查到："<<id<<"号职工，请输入新职工号："<<endl;
                cin>>newId;
                cout<<"请输入新姓名："<<endl;
                cin>>newName;
                cout<<"请输入新岗位："<<endl;
                cin>>newNum;
                this->m_EmpArray[index]->m_id = newId;
                this->m_EmpArray[index]->m_name = newName;
                this->m_EmpArray[index]->m_num = newNum;
                cout<<"修改成功"<<endl;
                this->save();
            }else{
                cout<<"修改失败，查无此人"<<endl;
            }
        }
    }
    void WorkerManager::findEmp()
    {
        if(this->m_FileIsEmpty){
            cout<<"文件不存在或记录为空"<<endl;
        }else{
            cout<<"请输入查找的方式"<<endl;
            cout<<"1、按职工编号查找"<<endl;
            cout<<"2、按职工姓名查找"<<endl;
            int select;
            cin>>select;
            if(select == 1){
                int id;
                cout<<"请输入查找的职工编号"<<endl;
                cin>>id;
                int index = isExist(id);
                if(index != -1){
                    this->m_EmpArray[index]->showInfo();
                }else{
                    cout<<"查无此人"<<endl;
                }
            }else if(select == 2){
                string name;
                cout<<"请输入查找的职工姓名"<<endl;
                cin>>name;
                bool flag = false;
                for(int i = 0; i < this->m_EmpNum; i++){
                    if(this->m_EmpArray[i]->m_name == name){
                        this->m_EmpArray[i]->showInfo();
                        flag = true;
                    }
                }
                if(flag == false){
                    cout<<"查无此人"<<endl;
                }
            }else{
                cout<<"输入有误"<<endl;
            }
        }
    }
    void WorkerManager::sortEmp()
    {
        if(this->m_FileIsEmpty){
            cout<<"文件不存在或记录为空"<<endl;
        }else{
            cout<<"请选择排序方式"<<endl;
            cout<<"1、按职工号升序"<<endl;
            cout<<"2、按职工号降序"<<endl;
            int select;
            cin>>select;
            for(int i = 0; i < this->m_EmpNum; i++){
                int minOrMax = i;//声明最小值或最大值下标
                for(int j = i+1; j < this->m_EmpNum; j++){
                    if(select == 1){//升序
                        if(this->m_EmpArray[minOrMax]->m_id > this->m_EmpArray[j]->m_id){
                            minOrMax = j;
                        }
                    }else{//降序
                        if(this->m_EmpArray[minOrMax]->m_id < this->m_EmpArray[j]->m_id){
                            minOrMax = j;
                        }
                    }
                }
                //判断是否需要交换位置
                if(i != minOrMax){
                    worker * temp = this->m_EmpArray[i];
                    this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
                    this->m_EmpArray[minOrMax] = temp;
                }
            }
            cout<<"排序成功"<<endl;
            this->save();
            this->showEmp();
        }
    }
    void WorkerManager::cleanFile()
    {
        cout<<"确定清空？"<<endl;
        cout<<"1、确定"<<endl;
        cout<<"2、返回"<<endl;
        int select = 0;
        cin>>select;
        if(select == 1){
            ofstream ofs(FILENAME, ios::trunc);
            ofs.close();
            if(this->m_EmpArray != NULL){
                for(int i = 0; i < this->m_EmpNum; i++){
                    if(this->m_EmpArray[i] != NULL){
                        delete this->m_EmpArray[i];
                        this->m_EmpArray[i] = NULL;
                    }
                }
                this->m_EmpNum = 0;
                delete [] this->m_EmpArray;
                this->m_EmpArray = NULL;
                this->m_FileIsEmpty = true;
            }
            cout<<"清空成功"<<endl;
        }
    }