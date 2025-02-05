#include<iostream>
#include<string>
using namespace std;

class person
{
public:
    int A;
protected:
    int B;
private:
    int C;
};
//公共继承
class son1:public person
{
public:
 void func(){
    A = 10;//父类中的公共权限，子类中仍然是公共权限
    B = 10;//父类中的保护权限，子类中仍然是保护权限
    //C = 10;//父类中的隐私权限，子类不可继承
 }
};
//保护继承
class son2:public person
{
public:
 void func(){
    A = 10;//父类中的公共权限，子类中是保护权限
    B = 10;//父类中的保护权限，子类中仍然是保护权限
    //C = 10;//父类中的隐私权限，子类不可继承
 }
};
//私有继承
class son3:public person
{
public:
 void func(){
    A = 10;//父类中的公共权限，子类中是私有权限
    B = 10;//父类中的保护权限，子类中是私有权限
    //C = 10;//父类中的隐私权限，子类不可继承
 }
};