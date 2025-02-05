#include<iostream>
#include<string>
using namespace std;

class goodf; // 前置声明 goodf 类

class building
{
    friend void goodGay(building *building); // 全局函数作为友元
    friend class goodmate; // 声明 goodmate 为友元类
    //friend void goodf::visit(); // 声明 goodf::visit 为友元函数
private:
    string m_bedroom;
public:
    string m_sittingroom;
    building(){
        m_sittingroom = "客厅";
        m_bedroom = "卧室";
    }
};

// 友元类
class goodmate
{
public:
    goodmate(){
        m_building = new building; // 在堆区开辟一个新的 building 对象
    }
    ~goodmate() {
        delete m_building; // 释放内存
    }
    void visit(){
        cout << "类，正在访问" << m_building->m_sittingroom << endl;
        cout << "类，正在访问" << m_building->m_bedroom << endl; // 访问私有成员
    }
    building * m_building;
};

// 友元函数
class goodf
{
public:
    goodf(){
        f_building = new building; // 在堆区开辟一个新的 building 对象
    }
    ~goodf() {
        delete f_building; // 释放内存
    }
    void visit(){
        cout << "成员函数，正在访问" << f_building->m_sittingroom << endl;
        //cout << "成员函数，正在访问" << f_building->m_bedroom << endl;// 访问私有成员
    }
    building * f_building;
};

// 全局函数，作为友元函数，可以访问私有成员
void goodGay(building *building){
    cout << "全局函数，正在访问" << building->m_sittingroom << endl;
    cout << "全局函数，正在访问" << building->m_bedroom << endl; // 访问私有成员
}

int main(){
    building mybuilding; // 创建一个 building 对象
    goodmate gg;
    goodf gf;
    gf.visit(); // 通过 goodf 类访问
    gg.visit(); // 通过 goodmate 类访问
    goodGay(&mybuilding); // 通过全局函数访问
    system("pause");
    return 0;
}
