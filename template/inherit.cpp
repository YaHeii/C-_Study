#include <iostream>
#include <string>
using namespace std;
//当子类继承的父类是一个类模板是，子类在声明的时候，要指定出父类中T的类型
//如果不指定，编译器无法给子类分配内存
//如果想灵活指定出父类中T的类型，子类也需要变为类模板
template<class T>
class base
{
public:
    T m;
};
class son:public base<int>//必须要知道父类中的T类型，才能继承
{
};
template<class T1,class T2>
class son2:public base<T2>//如果想灵活指定出父类中T的类型，子类也需要变为类模板
{
    T1 obj;
};
int main(){
    son s1;
    son2<int,char>s2;//T1为int,T2为char
    cout<<sizeof(s1)<<endl;
    cout<<sizeof(s2)<<endl;
    system("pause");
    return 0;
}