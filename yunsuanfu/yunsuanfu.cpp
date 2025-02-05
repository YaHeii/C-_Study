#include <iostream>
#include <string>
using namespace std;

int main(){
    //赋值 Cin用法
    //整型
    int a =0;
    cout <<"请给整型变量a赋值："<<endl;
    cin>>a;
    cout <<"整型变量a="<<a<<endl;
    //浮点型
    float b=3.14f;10;
    cout <<"请给浮点变量b赋值："<<endl;
    cin>>b;
    cout <<"整型变量b="<<b<<endl;
    //字符型
    char c='a';
    cout <<"请给字符变量c赋值："<<endl;
    cin>>c;
    cout <<"整型变量c="<<c<<endl;
    //字符串型
    string d ="abd";
    cout <<"请给字符变量d赋值："<<endl;
    cin>>d;
    cout <<"整型变量d="<<d<<endl;

     //运算符
    int e=10; 
    int f=3;
    cout << e+f<<endl;
    cout << e*f<<endl;
    cout << e-f<<endl;
    cout << e/f<<endl; //两个整数做除法，结果仍然是整数，将小数部分去掉
    cout << e%f<<endl;
    cout << e++*10<<endl;//后置递增，先进行表达式运算然后+1       =100  e=11
    cout << ++e*10<<endl;//前置递增，先让变量+1，然后进行表达式运算=110  e=11
    cout << (e<=f)<<endl;//比较运算符需要括号
    cout << !e<< endl;//除了0都是真




    system("pause");
    return 0;

}