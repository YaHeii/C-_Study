#include<iostream>
#include<string>
using namespace std;
class person
{
public: 
//所有对象都共享一份数据，如果在任一个对象中修改，那么其他对象数据也会被修改
//编译极端就分配内存
//类内声明，类外初始化 
//静态变量也是有访问权限的，如果在private下类外不可访问。
    static int m_a;
    static void func(){
        cout<<"静态变量m_a在静态函数可被调用"<<endl;//静态成员函数只能够访问静态成员变量
                                                //静态成员函数同样有访问权限
    }
};
int person::m_a = 100;//person作用域下的变量声明
int main(){
    cout << person::m_a<<endl;//对于静态变量的访问方式可以通过作用域来访问
                            //也可以通过对象来访问 person.m_a
    person::func();
    system("pause");
    return 0;
}
