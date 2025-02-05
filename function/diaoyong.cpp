#include <iostream>
using namespace std;

int add(int num1,int num2);//函数声明，用于提前告知编译器函数的存在，方便将编写函数放后。声明可以有多次，但是定义只能有一次
void change(int a,int b);//对于不返回值的函数，使用void声明
int main(){
    int a = 0;
    int b = 0;
    int c = 0;

    cout<<"输入a"<<endl;
    cin >> a;
    cout<<"输入b"<<endl;
    cin >> b;
    c = add(a,b);
    cout << "a与b的和："<<c <<endl;

    cout <<"ab值交换"<<endl;
    change(a,b);
    cout<<"实参a = "<<a<<endl;
    cout<<"实参b = "<<b<<endl;
    system("pause");

    return 0;
}
                            //我们还可以对参数设置默认值如int num1 = 10;这样在传参时，可以少传一个参数
                            //如果某个位置有了默认参数，那么从左至右都应该有默认参数。
                            //声明与实现只能有一个默认参数
int add(int num1,int num2)
{
    int sum = num1+num2;
    return sum;
}
//占位参数
// 通过填写一个数据类型，而不定义一个变量，从而起到占位的作用，同时也可以定义默认参数
void change(int a,int b)
{
    int temp = 0;
    temp = a;
    a = b;
    b = temp;
    cout <<"形参a = "<<a<<endl;
    cout <<"形参b = "<<b<<endl;//函数只改变形参，而不改变实参
}
