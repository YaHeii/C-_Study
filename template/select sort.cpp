#include <iostream>
using namespace std;
#include <string>
//实现通用选择排序
//char,int

//普通函数和函数模板的区别
//普通函数在调用的时候会发生隐式类型转换
//函数模板在显式指定类型时会发生，隐式类型推导不可以。
//eg：a = 10 b = c
//    a+c = 109


//在模板与普通函数之间可以发生重载
//普通函数优先调用，也可以通过空模板参数列表来强制调用函数模板
//函数模板可以发生重载，可以通过改变函数输入参数的类型、数量等来进行重载
//如果函数模板能够产生更好的匹配，那么优先调用函数模板。即参数类型不一致时，优先调用函数模板
template <typename T>
void myswap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
    cout<<"函数模板调用"<<endl;
}
//强制调用函数模板
//myswap<>(a,b);
void myswap(int &a, int &b)
{
    cout<<"普通函数调用"<<endl;
}

template <typename T>
void Sort(T arr[],int len)
{
    for(int i = 0;i<len;i++)
    {
        int max = i;
        for(int j = i+1;j<len;j++)
        {
            if(arr[j]>arr[max])
            {
                max = j;
            }
        }
        if(max!=i)
        {
            myswap(arr[max],arr[i]);
        }
    }
}
template <typename T>
void printArray(T &arr,int len)
{
    for(int i = 0;i<len;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    //char arr[] = "ghdrj";
    int arr[] = {5,2,3,6,1};
    int len = sizeof(arr)/sizeof(arr[0]);
    Sort(arr,len);
    printArray(arr,len);
    system("pause");
    return 0;
}
