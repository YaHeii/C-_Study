#include <iostream>
using namespace std;
int main(){
    //创建数组，临时变量
    int temp = 0;
    int start = 0;
    int end = 4;
    int a[5] = {22,45,78,36,69};
    cout<<"数组逆置前"<<endl;
    for ( int i = 0; i < 5; i++)
    {
       cout << a[i] <<" ";
    }
    cout<<endl;
    //数组逆置
    while(start<end){
    int temp = a[start];
    a[start] = a[end];
    a[end] = temp;
    start++;
    end--;
    }

    //输出
    cout<<"数组逆置后"<<endl;
        for ( int i = 0; i < 5; i++)
    {

       cout <<a[i]<<" ";
    }
}
