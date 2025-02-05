#include <iostream>
using namespace std;
int main(){
    int num = rand()%100+1;//生成0-99
    int val = 0;
    while(1){
    cin >>val;
    if(val>num){
        cout<<"太大了"<<endl;
    }else if (val<num)
    {
        cout<<"太小了"<<endl;
    }else {
        cout<<"猜对了"<<endl;
        break;
    }
    }
    system("pause");
    return 0;
}