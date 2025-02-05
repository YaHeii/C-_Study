#include<iostream>
#include<string>
using namespace std;
//当其他类对象作为苯类成员，构造时先构造类对象，再构造自身，析构顺序相反
class Phone
{
private:
    /* data */
public:
    Phone(string pName)
    {
        m_PName = pName;
    } 
    string m_PName;
};



class person
{

public:
    person(string name, string pName) : m_name(name), m_phone(pName)//列表赋初值
    {

    }
    //姓名
    string m_name;
    //手机
    Phone m_phone;

};
int main()
{
    person p("张三","小米");
    cout<<p.m_name<<"拿着"<<p.m_phone.m_PName<<"手机"<<endl;
    system("pause");
    return 0;
}
