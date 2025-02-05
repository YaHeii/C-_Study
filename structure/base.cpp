#include <iostream>
using namespace std;
#include <string>
struct Student
{
    string name;
    int age;
    int score;
}s3;//第三种方法直接加S3

void printf1(struct Student s ){
    cout << "姓名 ="<<s.name<<"年龄 ="<<s.age<<"分数"<<s.score<<endl;
}

void printf2(struct Student *m ){
    cout << "姓名 ="<<m->name<<"年龄 ="<<m->age<<"分数"<<m->score<<endl;
}

int main(){
    //通过结构提数据类型创建具体的学生
    //在创建结构体时，关键字struct可以省略
    //在定义结构体数据类型时，关键字struct不可以省略

    //sructure建立第一种方法
    struct Student s1;
    s1.name = "第一个";
    s1.age = 15;
    s1.score = 100;
    cout << "姓名 ="<<s1.name<<"年龄 ="<<s1.age<<"分数"<<s1.score<<endl;
    //structure建立第二种方法
    struct Student s2 ={"第二个",9,120};
    cout << "姓名 ="<<s2.name<<"年龄 ="<<s2.age<<"分数"<<s2.score<<endl;
    //第三种
    s3.name = "第三个";
    s3.age = 136;
    s3.score = 100;
    cout << "姓名 ="<<s3.name<<"年龄 ="<<s3.age<<"分数"<<s3.score<<endl;

    //结构体数组
    //把结构体放入数组方便维护
    Student stuArray[3]{
        {"数组第一个",18,120},
        {"数组第二个",19,120},
        {"数组第三个",120,120},
    };
    for(int i=0;i<3;i++){
        cout<<"姓名 = "<<stuArray[i].name<<"年龄 = "<<stuArray[i].age<<"成绩 = "<<stuArray[i].score<<endl;
    }


    struct Student *p = &s1;//定义一个结构体指针。
    cout<<"姓名："<<p->name<<"年龄："<<p->age<<"分数："<<p->score<<endl;//结构体指针输出

    //嵌套结构体


    //结构体的传参
    printf1(s2);//值传递
    printf2(&s3);//地址传递

    system("pause");
    return 0;
}