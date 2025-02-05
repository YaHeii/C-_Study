#include <iostream>
using namespace std;

template <typename T>//声明模板，T是一个类型参数
                    //<class T>也可以

void myswap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
int main(){
    int a = 1, b = 2;
    //自动类型推导传参,必须能够推导出两个参数类型一致
    //模板必须确定出T的类型，才可以使用
    //swap(a, b);
    //显示指定类型
    myswap<int>(a, b);
    cout <<"a = " <<a << " " <<"b = "<< b << endl;
    return 0;
}
//模板的局限性
//模板并不是万能的，有些特定的数据类型，需要提供相应的重载版本来支持
//模板的通用性并不是万能的，有些特定的数据类型，需要提供特定的实现版本
//重载方法
//bool mycompare(T &a, T &b)
//template <> bool mycompare<int>(int a, int b)