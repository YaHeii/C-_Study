#include<iostream>
#include <map>
#include<string>
using namespace std;

void test1()
{
    map<int,int> m;//默认构造
    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(2,20));//按照key值自动排序
    m.insert(pair<int,int>(3,30));//对组的赋值方式

    map<int,int>m2(m);//拷贝构造
}

//大小、交换操作
//empty size
//swap

//插入、删除
void test2()
{
    map<int,int> m;
    m.insert(pair<int,int>(1,10));//插入方法,第一种
    m.insert(make_pair(2,20));//第二种
    m[3] = 30;//[]重载的方法并未事先检测该处有没有值，可能发生数据覆盖的风险，不建议使用
            //但是可以用于查找
    m.erase(m.begin());//删除
    //m.erase(1);按照key值查找删除
}

//查找、统计
//find、count，利用迭代器接收
//map不允许重复插入key元素

//排序，利用仿函数，改变排序规则
