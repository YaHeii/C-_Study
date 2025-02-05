#include <iostream>
#include <deque>
using namespace std;
#include <algorithm>
//双端数组容器，可以对头端进行插入删除操作
//deque和vector的区别
//deque对头端插入删除速度快，vector对中间插入删除速度快，访问速度快
//deque没有容量的概念
//deque内存是分段连续的
//deque可以随机访问
//deque内部工作原理，重要（中控器）


//deque构造函数
void test1()
{
    deque<int> d1;//默认构造
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    deque<int> d2(d1.begin(), d1.end());//区间构造
    deque<int> d3(10, 100);//10个100
    deque<int> d4(d3);//拷贝构造
}
//其他操作与vector类似
//deque容器的排序
void test2()
{
    deque<int> d1;
    d1.push_back(3);
    d1.push_back(2);
    d1.push_back(5);
    d1.push_back(1);
    d1.push_back(4);
    sort(d1.begin(), d1.end());//排序
    for (deque<int>::iterator it = d1.begin(); it != d1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}