//STL内部建立了一些函数对象
//包括算数仿函数，关系仿函数，逻辑仿函数
#include <iostream>
#include <functional>
using namespace std;
#include <string>

//算数仿函数
void test01()
{
    plus<int> myplus;//加法仿函数
    negate<int>mynegat;//取反仿函数
    cout << myplus(10, 10) << endl;
    cout << mynegat(10) << endl;
}
//关系仿函数
void test02()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    sort(v1.begin(), v1.end(), greater<int>());//greater是大于号，降序输出
    for(vector<int>::iterator it = v1.begin();it != v1.end();it++){
        cout << *it << " ";
    }
}
 