#include <iostream>
using namespace std;
//函数的重载可以使函数名相同，提高复用性
//函数重载需要满足的条件
//1.同一个作用域下
//2.函数名称相同
//3.函数参数类型不同、或者个数不同、或者顺序不同.但返回值类型不足以区分函数重载的类型
void func(int &a)
{
    cout<<"函数func(int &a)被调用"<<endl;
}

void func(const int &a)
{
    cout<<"函数func(const int &a)被调用"<<endl;
}

int main(){
    int a  = 10;
    func(10);//const会被调用
    system("pause");
    return 0;
}