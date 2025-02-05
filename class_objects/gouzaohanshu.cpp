#include<iostream>
#include<string>
using namespace std;
class person
{
public:
    person(){
        cout<<"person的无参构造函数"<<endl;
    }
    person(int a){
        cout<<"person的有参构造函数"<<endl;
    }
    person(const person &p){//拷贝构造函数
        cout<<"person的拷贝构造函数"<<endl;

    }
};
//调用
void test(){
    //括号法
    person p;//默认构造函数调用，不需要加括号。

}   
int main(){
    test();
    person p2(10);//有参构造调用
    person p3(p2);//拷贝构造函数的调用

    system("pause");
    return 0;
}