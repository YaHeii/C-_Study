#include<iostream>
#include <string>
#include<ctime>
using namespace std;
struct student
{
    string sname;
    int score;
};

struct teacher
{
    //姓名
    string tname;
    //学生数组
    struct student sArray[5];

};
void allocateSpace(struct teacher tArray[], int len)
{
    string nameSeed = "ABCDE";
    for(int i = 0;i<len;i++){
        tArray[i].tname="teachen_";
        tArray[i].tname += nameSeed[i];
        for ( int j = 0; j < 5; j++)
        {
        tArray[i].sArray[j].sname = "student_";
        tArray[i].sArray[j].sname += nameSeed[j];
        tArray[i].sArray[j].score = rand() % 100;
        }
    }
}

printf(struct teacher tArray[],int len)
{
    for(int i = 0;i<len;i++)
    {
        cout<<"老师的名字"<<tArray[i].tname<<endl;
        for(int j = 0;j<5;j++)
        {
            cout<<"\t所带学生的名字"<<tArray[i].sArray[j].sname<<" "<<"该学生的分数"<<tArray[i].sArray[j].score<<endl;
        }
    }
}

int main(){
    //随机数种子
    srand((unsigned int)time(NULL));

    //创建三名老师的数组
    struct teacher tArray[3];
    int len = 3;

//通过函数给三名老师的信息赋值
    allocateSpace(tArray,len);

//打印所有老师以及所带学生的信息
    printf(tArray,len);
    system("pause");
    return 0;
}