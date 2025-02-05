#include<iostream>
#include<string>
using namespace std;
//虚析构函数
class animal
{
public:
    virtual void speak() = 0;//纯虚函数
   // virtual ~animal(){}//使父类的析构代码为虚析构可以i解决子类堆区数据无法释放的问题。
    virtual ~animal() = 0;//纯虚析构函数 声明

};
    animal:: ~animal()
{
    cout<<"纯虚析构函数"<<endl;
}
//调用纯虚析构函数，该类也会变成虚类，无法实例化
class cat:public animal
{
    public:
    cat(string name){
        m_Name = new string(name);//将名字复制到堆区
    }
    virtual void speak(){
        cout<<*m_Name<<"小猫在说话"<<endl;
    }
    string *m_Name;
    ~cat(){//虚析构函数
        if(m_Name!=NULL){
            delete m_Name;//堆区内存释放
            m_Name= NULL;
        }
    }
};
int main(){
    animal *animal = new cat("tom");
    animal->speak();
    delete animal;//使用父类指针指向子类对象，因此删除父类指针时，并不会调用子类析构函数，导致如果子类中有堆区数据，无法删除
    system("pause");
    return 0;
}