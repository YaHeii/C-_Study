#include <iostream>
using namespace std;
int main(){
    //创建二维数组
    int a[3][3]=
    {
        {100,100,100},
        {90,50,70},
        {60,70,80}
    };
    for(int i=0; i<3; i++)
    {
        int sum = 0;
        for(int j=0; j<3; j++)
        {
            sum+=a[i][j];
        
        }
        cout << sum <<" ";
        cout <<endl;
    }

    system("pause");
    return 0;
}