#include<iostream>
#include<string>
using namespace std;
//加号运算符重载
//运算符重载同样了以用于函数重载。
//成员函数重载
class person
{
public:
    int m_A;
    int m_B;
};
void operator<<(ostream &cout,person &p){//若改成ostream则能实现链式编程
    cout<<"m_A="<<p.m_A<<endl;
    cout<<"m_B="<<p.m_B<<endl;

}

int main(){
    person p1;
    p1.m_A = 10;
    p1.m_B = 20;
    cout<<p1;//由于返回是void，链式输出不能够加《《end
            //链式编程要求保证参数和返回值都是同一类型。


}