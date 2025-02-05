#include <iostream>
using namespace std;

void bubble(int *arr,int len){
    for(int i=0;i<len-1;i++){
        for(int j=0 ; j<len-1-i ; j++){
            //如果j》j+1，交换
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void printArray(int *arr,int len){
    for(int i = 0;i<len;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[6]{1,22,15,16,68,17};
    int len = sizeof(arr)/sizeof(arr[0]);
    bubble(arr,len);
    printArray(arr,len);
    system("pause");
    return 0;
}