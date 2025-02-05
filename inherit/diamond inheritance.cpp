#include<iostream>
#include<string>
using namespace std;

class  animal
{
public:
    int age;
};

class sheep :virtual public animal
{

};

class camel:public virtual animal
{

};

class alpaca :public sheep,public camel
{

};
int main(){
    alpaca yangtuo;
    //菱形继承导致数据有两份，需要加作用域解决
    //虚继承可以解决数据浪费的问题
    //继承之前加virtual
    yangtuo.sheep::age = 18;
    system("pause");
    return 0;
}