#include <iostream>
#include <string>

using namespace std;

int main(){

    //整型
    short num1 = 10;
    int num2 = 10;
    long num3 = 10;
    long long num4 = 10;
    //实型（浮点型 ）
    float f1 = 3.14f;
    double f2 = 3.14;
    //字符型
    char ch = 'a'; //单引号，且只有一个字符，并占用一个字节，字符型变量并不是把字符本身进行存储，而是将对应的ASCII码进行存储
                    //a-97  A-65
                    //0-31一般分给了控制字符，32-126是常规字符
    //转义字符
        //  \n换行    \\输出反斜杠    \t输出制表符  
    //字符串
        //C风格字符串
    char str1[] = "hello world";
        //C++风格
    string str2  = "hello world";//需要包含头文件string
    //bool类型
    bool flag = true;
    

    cout <<"num1 = \t"<<num1<<endl;
    cout <<"num2 = \t"<<num2<<endl;
    cout <<"num3 = \t"<<num3<<endl;
    cout <<"num4 = \t"<<num4<<endl;
    cout <<"f1 = \t"<<f1<<endl;
    cout <<"f2 = \t"<<f2<<endl;
    cout <<"ch = \t"<<ch<<endl;
    cout <<"str1 = \t"<<str1<<endl;
    cout <<"str2 = \t"<<str2<<endl;
    cout <<"flag = \t"<<flag<<endl;

    system("pause");
    return 0;

}