#include<iostream>
using namespace std;
int main (){
    int a = 10;
//引用的使用格式
    int &b=a;
    //int &b = 10,错误，引用必须使用一块合法的内存空间
    const int &ref = 10;//加上const后，编译器会讲代码修改为int temp = 10;const int &ref = temp;
                        //同时ref为只读，不可以修改
                   
    cout<<b<<endl;
   system("pause");
   return 0;
}