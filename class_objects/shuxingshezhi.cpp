#include<iostream>
using namespace std;
#include<string>
//将成员属性设置为私有
//可以实现控制读写权限
//可以检测写入的有效性
class Person
{
public:
    void setname(string set_name){
        name = set_name;
    }
    string get_name(){
        return name;
    }
    int get_age(){
        return age;
    }
    void set_idol(string set_idol){
        idol = set_idol;
    }
private:
    string name;//姓名，可读可写
    int age = 18;  //年龄，只读
    string idol;//idol 只写
};
int main(){
    Person p1;
    p1.setname("陈庆澎");
    p1.set_idol("小明");
    cout<<"姓名是："<<p1.get_name()<<endl;
    cout<<"年龄是："<<p1.get_age()<<endl;
    //cout<<"偶像是："<<p1.get_idol()<<endl;  只写，不可读
}