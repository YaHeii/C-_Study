//静态多态：函数重载、运算符重载、复用函数名
//动态多态，派生类和虚函数实现动态多态
//静态多态的函数地址早绑定，编译阶段确定函数地址
//动态多态的函数地址晚绑定，运行阶段确定函数地址
//一般要先定义一个抽象类，然后从抽象类继承
//多态可以实现结构清晰、可读性强
//可以实现函数接口的多样化，通过父类指针指向不同的子类，实现不同子类的函数
#include<iostream>
#include<string>
using namespace std;

class animal
{
    public:
   virtual void speak(){//需要执行地址晚绑定，否则函数地址过早确定无法实现猫（狗）说话，只能实现动物说话
   // void speak(){
        cout<<"动物在说话"<<endl;
    }
    //可以将这个函数修改为纯虚函数，因为始终未进行调用
    //virtual void speak() = 0;
    //当类中具有了纯虚函数，那么这个类也被称为抽象类
    //抽象类无法实例化对象
    //子类必须重写纯虚函数，否则也将属于抽象类
};
class cat:public animal
{

public:
    void speak(){
        cout<<"猫在说话"<<endl;
    }
};
class dog:public animal
{

public:
    void speak(){
        cout<<"狗在说话"<<endl;
    }
};
void dospeak(animal &animal)//父类指针指向子类对象
//animal *abc = new dog
{
    animal.speak();
}
int main()
{
    cat cat;
    dospeak(cat);
}