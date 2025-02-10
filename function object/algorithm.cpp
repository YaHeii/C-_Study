#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void print1(int val)
{
    cout<<val<<" ";
}
class print2
{
public:
    void operator()(int val)
    {
        cout<<val<<" ";
    }
};
//for_each算法,遍历
void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), print1);
    cout<<endl;
    for_each(v.begin(), v.end(), print2());
    cout<<endl;
}
//transform算法，容器传输
class my_transform
{
public:
    int operator()(int v)
    {
        return v;
    }
};
void test02()
{
    vector<int> v1;
    vector<int> v2;
    v2.resize(v1.size());//需要提前开辟空间
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    std::transform(v1.begin(), v1.end(), v2.begin(), my_transform());//原容器的开始，结束迭代器，目标容器的开始、结束迭代器
    for_each(v2.begin(), v2.end(), print1);
    cout<<endl;
}