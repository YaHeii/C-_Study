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
    // person operator+(person &p){//通过成员函数对加号运算符进行重载
    //     person temp;
    //     temp.m_A = this->m_A+p.m_A;
    //     temp.m_B = this->m_B+p.m_B;
    //     return temp;
    // }
};
//全局函数对加号运算符重载
person operator+(person &p1, person &p2){//全局函数对加号运算符重载
        person temp;
        temp.m_A = p1.m_A+p2.m_A;
        temp.m_B = p1.m_B+p2.m_B;
        return temp;

}
int main(){
    person p1;
    p1.m_A = 10;
    p1.m_B = 20;
    person p2;
    p2.m_A = 10;
    p2.m_B = 20;
    person p3 = p1+(p2);//加号重载的简写
                        //person p3  = p1.opreator+(p2)
    cout << "m_A="<<p3.m_A<<endl;
    cout << "m_B="<<p3.m_B<<endl;

}