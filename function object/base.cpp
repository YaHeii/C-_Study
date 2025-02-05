#include<iostream>
#include <string>
using namespace std;


//函数对象在使用时可以像普通函数那样调用，可以有参数，可以有返回值
//函数对象超过普通函数的概念，函数对象可以有自己的状态
//函数对象可以作为参数传递

class  MyAdd
{
public:
    int operator()(int v1,int v2)
    {
        return v1+v2;
    }
};
class  Myprint
{
public:
    int operator()(string s)
    {
        cout<<s<<endl;
    }
};
//函数对象在使用时可以像普通函数那样调用，可以有参数，可以有返回值
void test01()
{
    MyAdd myadd;
    cout<<myadd(10,10)<<endl;
}

void test02()
{
    Myprint myprint;
    cout<<myprint("www")<<endl;
}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}