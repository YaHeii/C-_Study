#include<iostream>
#include<string>
using namespace std;

void test1()
{
    string s1;//默认构造
    const char* str = "hello world";//字符串常量，不可修改，用const
    string s2(str);//有参构造
    string s3(s2);//拷贝构造
    string s4(10, 'a');//10个a
}

void test2()
{
    string a1;
    a1 = "hello world";//基本赋值

    string a2;
    a2 = a1;//拷贝赋值

    string a3;
    a3 = 'a';//字符赋值

    string a4;
    a4.assign("hello world");//成员函数赋值

    string a5;
    a5.assign("helloworld",5);//将字符串的前五个字符赋值

    string a6;
    a6.assign(a5);//拷贝赋值

    string a7;
    a7.assign(10, 'a');//10个a
}

void test3()
{
    string b1 = "我";
    b1 += "爱";//字符串拼接
    b1.append("你");//成员函数字符串拼接
    b1.append("hello world", 2,1);//将字符串的从第二个字符开始的一个字符拼接
    b1.append(10, 'a');//10个a
}

void test4()
{
    //字符串查找    
    string c1 = "hello world";
    int pos = c1.find("world");//查找world的位置
    //rfind是从右往左找,find是从左往右找
    //字符串替换
    c1.replace(pos, 5, "haha");//从0开始的5个字符替换为haha
}
//访问单个字符
void test5()
{
    string c1 = "hello world";
    for(int i = 0; i < c1.size(); i++)
    {
        cout << c1[i] << " ";
    }//下标访问
    for(int i = 0; i < c1.size(); i++)
    {
        cout << c1.at(i) << " ";
    }//at访问
    c1[0] = 'H';//修改第一个字符
}
//截取操作
void test6()
{
    string email = "15146681278@163.com";
    int pos = email.find("@");
    string username = email.substr(0, pos);//截取用户名
}