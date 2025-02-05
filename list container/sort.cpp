#include <iostream>
#include <string>
#include <list>
using namespace std;

class person
{
public:
    person(string name,int age,int height)
    {
        m_name = name;
        m_age = age;
        m_height = height;
    }
    string m_name;
    int m_age;
    int m_height;
};
//排序规则,首先按照年龄升序，其次按照身高降序。
bool compare(person &p1,person &p2)
{
    if(p1.m_age == p2.m_age)
    {
        return p1.m_height>p2.m_height;
    }else{
    return p1.m_age<p2.m_age;
    }
}
int main(){
    list<person> L;
    person p1("陈",23,174);
    person p2("汪",23,165);
    person p3("钱",46,180);
    L.push_back(p1);
    L.push_back(p2);
    L.push_back(p3);
    cout<<"排序前："<<endl;
    for(list<person>::iterator it = L.begin();it != L.end();it++)
    {
        cout<<"姓名："<<(*it).m_name<<"年龄："<<(*it).m_age<<"身高："<<(*it).m_height<<endl;
    }
    cout<<"排序后："<<endl;
    L.sort(compare);
    for(list<person>::iterator it = L.begin();it != L.end();it++)
    {
        cout<<"姓名："<<(*it).m_name<<"年龄："<<(*it).m_age<<"身高："<<(*it).m_height<<endl;
    }
}