#include<iostream>
#include<string>
using namespace std;
#include"myArray.hpp"
class person
{
public:
    person(){};//不能少默认(无参)构造函数，因为在堆区new出来Person类型的数组的时候，编译器会使用默认构造函数自动初始化这些元素，然后才是你自己的有参构造函数
    person (string name,int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;
};

void printArray(myArray<int>&arr)
{
    for(int i = 0;i<arr.getSize();i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    myArray<int>arr1(5);
    for ( int i = 0; i < 5; i++)
    {
        //尾插法插入数据
        arr1.Push_Back(i);
    }
    cout << "arr1的打印输出为："<< endl;
    printArray(arr1);
    cout <<"arr1的容量为："<<arr1.getCapacity()<<endl;
    cout <<"arr1的大小为："<<arr1.getSize()<<endl;
    myArray<int>arr2(arr1);//调用拷贝构造
    cout << "arr2的打印输出为："<< endl;
    printArray(arr2);
    //伪删法
    arr2.Pop_Back();
    cout << "arr2的尾删后输出为："<< endl;
    printArray(arr2);
    cout <<"arr2的容量为："<<arr2.getCapacity()<<endl;
    cout <<"arr2的大小为："<<arr2.getSize()<<endl;
    //测试自定义数据类型
    myArray<person>arr3(10);
    person p1("孙悟空",999);
    person p2("猪八戒",888);
    person p3("唐僧",777);
    person p4("沙僧",666);
    person p5("白龙马",555);
    //将数据插入到数组中
    arr3.Push_Back(p1);
    arr3.Push_Back(p2);
    arr3.Push_Back(p3);
    arr3.Push_Back(p4);
    arr3.Push_Back(p5);
    for(int i = 0;i<arr3.getSize();i++)
    {
        cout << "姓名：" << arr3[i].m_Name << " 年龄：" << arr3[i].m_Age << endl;
    }
    system("pause");
    return 0;
}