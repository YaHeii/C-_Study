#include<iostream>
#include<string>
using namespace std;

class person{
public:
    person(int age){
        m_age = new int(age);//将变量放置堆区
    }
    int *m_age;
    ~person()//堆区内存需要手动释放
    {
        if(m_age != NULL)
        {
            delete m_age;//浅拷贝会导致堆区内存重复释放。报错
            m_age = NULL;
        }
    }
};
// person& operator=(person &p){
//     //应该先判断是否有属性在堆区，如果有，先释放干净，然后进行深拷贝。
//     if (m_age !=NULL)
//     {
//         delete m_age;
//         m_age = NULL;
//     }
//     //深拷贝
//     m_age = new int(*p.m_age);
//     return *this;
// }
int main(){
    person p1(18);
    person p2(20);
    p2 = p1;//浅拷贝操作
    cout<<"1年龄为："<<*p1.m_age<<endl;
    cout<<"2年龄为："<<*p2.m_age<<endl;
    system("pause");
    return 0;
}