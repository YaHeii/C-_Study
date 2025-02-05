#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main(){
    //写文件
    //创建流对象
    ofstream ofs;
    //指定打开方式
    ofs.open("test.txt",ios::out);
    //写
    ofs<<"姓名：陈庆澎"<<endl;
    ofs<<"性别：男"<<endl;
    //关闭文件
    ofs.close();
    
    //读文件
    //创建流对象
    ifstream ifs;
    //打开文件并判断是否成功
    ifs.open("test.txt",ios::in);
    if(!ifs.is_open()){
        cout<<"文件打开失败"<<endl;
        return 0;
    }
    //读数据
    //第一种方法
    // char buf[1024]={0};
//     while(ifs>>buf)//当ifs读不到数据时返回假
//     {
//         cout<<buf<<endl;
//     }
    //第二种
    // char buf[1024]={0};
    // while(ifs.getline((buf),sizeof(buf)))
    // {
    //     cout<<buf<<endl;
    // }
    //第三种
    string buf;
    while(getline(ifs,buf))
    {
        cout<<buf<<endl;
    }
    ifs.close();
   system("pause");
   return 0;

}