#include <iostream>
#include <set>
using namespace std;

void print(set<int> &s1)
{
    for(set<int>::iterator it = s1.begin();it!=s1.end();it++)
    {
        cout << *it<<endl;
    }
    cout <<endl;
}
//构造函数
void test1()
{
    set<int> s1;//默认构造
    s1.insert(10);//插入数据，只有insert
    s1.insert(40);
    s1.insert(30);//插入后自动排序
                //set和mutiset，区别在于mutiset中元素允许重复，set容器元素不允许重复
    //遍历
    print(s1);

    set<int>s2(s1);//拷贝构造

    set<int>s3;
    s3 = s2;//赋值构造
}
//set大小操作进可以返回容器内元素个数，和判断是否为空。不可以重设大小
//交换还是swap函数

//删除函数s1.erase()

//查找、统计
//find、count
//验证set与mutiset区别
void test2(){
    set<int>m;
    //创建对组
    pair<set<int>::iterator,bool> ret = m.insert(10);//s.insert的返回值类型是pair
    //第一种
    //pair<string, int>p("tom",20);
    //第二种
    //pair<string,int> p=make_pair("tom",20)
    //分别接收两个值 
    //输出，p.first p.second
    if(ret.second)//第二个元素，bool值
    {
        cout<<"第一个数据插入成功"<<endl;
    }else{
        cout<<"第一次插入失败"<<endl;
    }
    pair<set<int>::iterator,bool> ret1 = m.insert(10);//s.insert的返回值类型是pair（对组数据类型）
    if(ret1.second)//第二个元素，bool值
    {
        cout<<"第二个数据插入成功"<<endl;
    }else{
        cout<<"第二次插入失败"<<endl;
    }
}

//改变set容器内部元素排列规则
//对于自定义的数据类型，都需要指定排列顺序
//通过仿函数实现，利用类重载（）