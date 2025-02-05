#include<iostream>
#include<string>
using namespace std;

class m_print
{
public:
void operator()(string test){
    cout<<test<<endl;//对于（）的重载，称为仿函数。
}
};
void m_print2(string test){
    cout<<test<<endl;//函数调用，与仿函数非常

}
int main(){
    m_print mp;
    mp("hello world");
    m_print2("hello world");
}
//匿名函数对象？
//一个类型加上一个小括号，再加上参数。