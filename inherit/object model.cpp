#include<iostream>
#include<string>
using namespace std;

class person
{
public:
    person(){
        A=200;
        cout<<"base构造函数"<<endl;
    }
    ~person(){
        cout<<"base析构函数"<<endl;
    }
    int A;
protected:
    int B;
private:
    int C;
};
class son:public person
{
public:
    son(){
        A = 100; 
        cout<<"son构造函数"<<endl;
    }
    ~son(){
        cout<<"son析构函数"<<endl;
    }
    int A;
};
int main(){
    cout<<"size of son:"<<sizeof(son)<<endl;//16
                                            //在子类中是将父类所有成员（非静态）重新保存
                                            //父类中私有属性会被编译器隐藏，因此是访问不到但是会被继承。
    son s;//在构建子类时需要先构建父类。析构顺序相反
    cout<<"son下A:"<<s.A<<endl;
    cout<<"person下A:"<<s.person::A<<endl;//同样，对于子父类重名变量的访问，子类也会保存，但是编译器隐藏。只需要限定其作用域。
                                        //同名成员函数的访问也是
                                        //如果子类中有同名成员函数，那么父类中所有的同名函数都会被隐藏，需要加入作用域。
                                        //同名静态成员的访问方式与非静态成员相同，但需注意，有两种访问方式，通过类和对象
    system("pause");
    return 0;
}