#include <iostream>
#include <stack>
using namespace std;
//栈不允许遍历行为
//栈可以判断是否为空
//栈可以返回元素个数

//栈的基本操作
void test1()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout << "栈的大小：" << s.size() << endl;
    while(!s.empty())
    {
        cout << s.top() << " ";//查看栈顶元素
        s.pop();//弹出栈顶元素
    }
    cout<<"现在大小："<<s.size()<<endl;
}
int main()
{
    test1();
    return 0;
}