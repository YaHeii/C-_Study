#include <iostream>
using namespace std;
#include <vector>

void print(vector<int>&v)
{
    for (vector<int>::iterator it  = v.begin();it!=v.end();it++)
    {
        cout << *it << " ";
    }
}

void test1()
{
    vector<int> v1;//默认构造
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    print(v1);

    vector<int> v2(v1.begin(), v1.end());//区间构造
    print(v2);

    vector<int> v3(v2);//拷贝构造

    vector<int> v4(10, 100);//10个100,n个element
}
void test2()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    vector<int> v2;
    v2 = v1;//拷贝赋值

    vector<int> v3;
    v3.assign(v2.begin(), v2.end());//区间赋值

    vector<int> v4;
    v4.assign(10, 100);//10个100
}
void test3()
{
    vector<int> v1;
    for (int i = 0;i<10;i++)
    {
        v1.push_back(i);
    }
    if(v1.empty())
    {
        cout<<"v1为空"<<endl;
    }
    else
    {
        cout<<"v1不为空"<<endl;
        cout<<"v1的大小为："<<v1.size()<<endl;//大小是动态变化的
        cout<<"v1的容量为："<<v1.capacity()<<endl;//容量是动态变化的，容量大于等于大小
        v1.resize(15);//重新指定大小
    }
}
//vector容器的插入和删除
void test4()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    v1.insert(v1.begin(), 100);//头插
    v1.insert(v1.end(), 100);//尾插
    v1.insert(v1.begin() + 3, 100);//指定位置插入
    v1.insert(v1.begin(), 3, 100);//指定位置插入n个元素
    v1.erase(v1.begin());//删除第一个元素
    v1.erase(v1.begin(), v1.end());//删除区间
    v1.clear();//清空
}
//vector容器的数据存取
void test5()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    cout << v1.front() << endl;//第一个元素
    cout << v1.back() << endl;//最后一个元素
    cout << v1[0] << endl;//下标访问
    cout << v1.at(0) << endl;//at访问
}
//vector容器的互换
//实际在使用，一般不会使用swap，因为swap会导致两个容器的迭代器失效
//巧用swap可以收缩内存空间
//vector<int>(v) swap(v);

void test6()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    vector<int> v2;
    for (int i = 10; i > 0; i--)
    {
        v2.push_back(i);
    }
    v1.swap(v2);//互换
}
//vector容器的预留空间
void test7()
{
    vector<int> v1;
    v1.reserve(100000);//预留空间
    int* p = NULL;
    int num = 0;//记录扩容次数
    for (int i = 0; i < 100000; i++)
    {
        v1.push_back(i);
        if (p != &v1[0])
        {
            p = &v1[0];
            num++;
        }
    }
    cout << "num:" << num << endl;
}