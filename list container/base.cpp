#include <iostream>
#include <list>
using namespace std;
//list是一种双向循环链表，数据内部包括数据本身以及上一节点和下一节点的指针，且最后一个节点记录第一个节点位置，第一个节点记录最后一个节点位置
//链表的优点是可以对任意位置进行插入和删除
//缺点是，对于容器内的元素遍历速度没有数组快
//占用空间比数组大
//支持头部插入、头部删除
//支持尾部插入、尾部删除
//不支持随机访问。迭代器只能前移或后移

//构造函数
void test1()
{
    list<int> l1;//默认构造
    list<int> l2(10, 5);//10个5
    list<int> l3(l2.begin(), l2.end());//区间构造
    list<int> l4(l3);//拷贝构造
    for (list<int>::iterator it = l4.begin(); it != l4.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
//赋值和交换，与vector相同

//list的数据存取
void test2()
{
    list<int> l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);
    l1.push_back(5);
    l1.push_back(6);
    l1.push_back(7);
    l1.push_back(8);
    l1.push_back(9);
    l1.push_back(10);
    for (list<int>::iterator it = l1.begin(); it != l1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << "第一个元素：" << l1.front() << endl;
    cout << "最后一个元素：" << l1.back() << endl;//不可以用[]访问//不可以用at访问
    cout << endl;
    //sort(l1.begin(), l1.end());//所有不支持随机访问迭代器的容器，不支持标准算法
                            //但是容器内部会提供成员函数完成这项功能
    l1.sort();//成员函数实现排序
              //可以通过仿函数来实现自定义排序
}                                                
   