#include <iostream>
#include <string>
using namespace std;
#include "person.cpp"//包含源文件,来连接类模板的声明和实现
//第二种解决无法链接的方法
//将类模板的声明和实现写到一个文件中，后缀名改为.hpp
// #include "person.hpp"
int main()
{
    person<string,int>p1("孙悟空",999);
    p1.showPerson();
    system("pause");
    return 0;
}