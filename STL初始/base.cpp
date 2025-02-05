 #include <vector>
 #include <iostream>
 #include <algorithm>
 using namespace std;
// vector容器存放自定义数据类型
class person
{
public:
    person(string name,int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;
};

void print(int val)
{
    cout<<val<<endl;
}

 void test01()
 {
    //创建vector容器,数组
    vector<int> v1;
    //尾插数据
    v1.push_back(10);
    v1.push_back(20);

    //通过迭代器访问容器中的数据
    vector<int>::iterator itBegin = v1.begin();//起始迭代器，指向第一个元素
    vector<int>::iterator itEnd = v1.end();//结束迭代器，指向最后一个元素的下一个位置
   //第一种遍历方式
    // while(itBegin != itEnd)
    // {
    //     cout<<*itBegin<<endl;
    //     itBegin++;
    // }
    //第二种遍历方式
    // for(vector<int>::iterator it = v1.begin();it !=v1.)
    // {
    //     cout<<*it<<endl;
    // }
    //第三种遍历方式，利用STL提供的遍历算法
    for_each(v1.begin(),v1.end(),print);//回调函数

 }
 void test02()
 {
    vector<person*> v2;//`存放的是person*类型的数据
    person p1("aaa",10);
    person p2("bbb",20);
    person p3("ccc",30);
    v2.push_back(&p1);
    v2.push_back(&p2);
    v2.push_back(&p3);

    for(vector<person *>::iterator it = v2.begin();it != v2.end();it++)
    {
        cout<<"Name:"<<(*it)->m_Name<<" Age:"<<(*it)->m_Age<<endl;
    }

 }
     int main()
    {
        test02();
        return 0;
    }