#include<iostream>
using namespace std;
#include <vector>
#include<string>
#include<algorithm>
class Greater5
{
public:
    bool operator()(int val)//仿函数接收参数称为谓词，接收一个参数为一元谓词，接收两个参数为二元谓词
    {
        return val>5;
    }
};

void test1()
{
    vector<int> v;
    for(int i = 0;i < 10;i++){
        v.push_back(i);
    }
    //查找容器内大于五的数字
    //greater5是一个匿名函数对象
    vector<int>::iterator it = find_if(v.begin(), v.end(), Greater5());
    if (it == v.end())
    {
        cout<<"没有找到"<<endl;
    }else{
        cout<<"找到了："<<*it<<endl;
    }
}
int main()
{
    test1();
    system("pause");
    return 0;
}