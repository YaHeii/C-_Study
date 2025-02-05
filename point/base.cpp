#include <iostream>
using namespace std;
int main(){
    int a = 10;
    int *p;//int *p = &a;
    p = &a;
    cout<<"a的地址为："<<&a<<endl;
    cout<<"a的地址为："<<p<<endl;
    cout<<"a变量为："<<*p<<endl;//解引用

    cout <<"sizeof(int*)="<<sizeof(p)<<endl;//指针占用内存为8个字节，编译器64位7
    // int *n=NULL;                             //空指针用于为指针进行初始化，
    // *n = 100;                                //空指针不能够进行访问
                                            //空指针指向地址为0
                                            //0-255为系统占用地址
    // int *m = (int *)0X1100;                //野指针，指针变量指向非法空间
    // cout<<*m<<0X1100;                      //不可主动指向地址

    // const int *q = &a;                       //常量指针，指针的指向可以修改，指针指向的值不可以修改
    // int *const r = &a;                       //指针常量，指针的指向不可以改，指针指向的值可改
    // const int *const s = &a;                       //const 及修饰指针也修饰常量，指向和指向的值都不可改

//数组指针
    int arr[5]{1,2,3,4,5};
    cout<<"第一个元素"<<arr[0]<<endl;
    int *q = arr;//arr为数组首地址
    q=q+2;
    cout<<"第3个元素"<<*q<<endl;
//指针和函数
//值传递，看function，不改变实参部分
//地址传递
    //int swap(int *p1,int *p2){}
    //swap(&p1,&p2)
    //可以改变实参的数值
    system("pause");
    return 0;
}