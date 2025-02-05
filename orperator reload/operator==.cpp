#include<iostream>
#include<string>
using namespace std;
class person
{
public:
   
 person(string name,int age)
 {
    m_name = name;
    m_age = age;
 }
 bool operator==(person &p)
 {
    if(this->m_name == p.m_name && this->m_age == p.m_age)
    {
        return true;
    }else{
        return false;
    }
 }
    string m_name;
    int m_age;
};

int main(){
    person p1("陈",23);
    person p2("陈",23);
    cout<<"姓名:"<<p1.m_name<<endl;
    cout<<"姓名:"<<p1.m_name<<endl;
    if(p1==p2){
        cout<<"为同一人"<<endl;
    }else{
        cout<<"不为同一人"<<endl;
    }
    system("pause");
    return 0;
}