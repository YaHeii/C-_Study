#include<iostream>
using namespace std;
class person//C++中class与struct区别不大，只是struct的默认权限为私有，class的默认权限为共有
{
    //访问权限
public://protected：保护权限，成员类内可以访问，类外不可以访问；public：公共权限，成员类内、类外都可以使用；private：私有权限，成员类内可以访问，类外不可以访问
        //保护权限和私有权限的区别在于继承方面，父类于子类中，保护权限是可以继承的，而私有权限是不可以继承的。
    //属性
    string m_name;
    person(){
        //构造函数，只调用一次，完成初始化。
        //没有返回值，也不用写void
        //函数名与类名相同
        //构造函数可以有参数，可以发生重载
        //创建对象时，构造函数自动调用
    }
    ~person(){
        //析构函数,对象在销毁前会调用析构函数，且只调用1次
        //没有返回值，且不写void。
        //函数名与类名相同，且不写void
        //析构函数没有参数，不可重载

    }

protected:
    string m_car;
private:
    int m_password;
public:
    void func(){
        m_name = "chen";
        m_car = "benzi";
        m_password = 12345;
    }
};
int main (){
    person p1;
    p1.m_name = "wang";
    //p1.m_car="mercedes" 代码外不可访问
    system("pause");
    return 0;
}