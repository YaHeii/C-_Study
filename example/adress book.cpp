#include <iostream>
#include<string>
using namespace std;

#define MAX 1000
//菜单界面
void showMenu()
{
    cout<<"1.添加联系人"<<endl;
    cout<<"2.显示联系人"<<endl;
    cout<<"3.删除联系人"<<endl;
    cout<<"4.查找联系人"<<endl;
    cout<<"5.修改联系人"<<endl;
    cout<<"6.清空联系人"<<endl;
    cout<<"0.退出通讯录"<<endl;
}

struct person{
    string name;
    int sex;//1为男。2为女
    int age;
    string number;
    string address;
};

struct address_book
{
    //联系人数组
    struct person personArray[MAX];
    int len;//联系人个数
};

void addPerson(struct address_book *abs)
{
    if(abs->len==MAX){
        cout<<"联系人已满"<<endl;
        return;
    }else{
        cout<<"请输入姓名："<<endl;
        cin >> abs->personArray[abs->len].name;
        cout<<"请输入性别："<<endl;
        cout<<"1--男"<<endl;
        cout<<"2--女"<<endl;
        int sex=0;
        while (true){
            cin>>sex;
            if(sex==1||sex==2){
                abs->personArray[abs->len].sex = sex;
                break;
            }
        }
        cout<<"请输入年龄："<<endl;        
        cin >> abs->personArray[abs->len].age;
        cout<<"请输入电话："<<endl;        
        cin >> abs->personArray[abs->len].number;
        cout<<"请输入住址："<<endl;
        cin >> abs->personArray[abs->len].address;
        abs->len++;
        cout<<"添加成功"<<endl;
    }
    //system("pause");
    //system("cls");1

}

void showPerson(address_book *abs)
{
    if(abs->len == 0){
        cout<<"通讯录中无信息"<<endl;
    }else{
        for(int i = 0;i<abs->len;i++){
            cout<<"姓名是"<<abs->personArray[i].name<<endl;
            cout<<"性别是"<<abs->personArray[i].sex<<endl;
            cout<<"年龄是"<<abs->personArray[i].age<<endl;
            cout<<"电话是"<<abs->personArray[i].number<<endl;
            cout<<"住址是"<<abs->personArray[i].address<<endl;
        }
    }
    //system("pause");
    //system("cls");
}
int detectPerson(address_book *abs,string name)
{
    for(int i = 0;i<abs->len;i++)
    {
        if (abs->personArray[i].name==name)
        {
            return i;//找到返回键i
        }
    }
    return -1;//遍历结束未找到，返回-1
}
void deletePerson(address_book *abs,string name)
{
    cout<<"输入要删除的联系人姓名："<<endl;
    int m;
    m = detectPerson(abs,name);
    if(m==-1){
        cout<<"查无此人"<<endl;
    }else{
        cout<<"您将删除此人"<<endl;
        for(int i = m;i<abs->len-1;i++){
            abs->personArray[i] = abs->personArray[i+1];//利用数据前移删除联系人
        }
        abs->len--;
        cout<<"删除成功";
    }
}

void findPerson(address_book *abs)
{
    string name;
    int m ;
    cout<<"请输入要查找的联系人："<<endl;
    cin >> name;
    m = detectPerson(abs,name);
    if (m == -1)
    {
        cout<<"未找到联系人"<<endl;
    }else{
        cout<<"姓名是："<<abs->personArray[m].name<<endl;
        cout<<"年龄是："<<abs->personArray[m].age<<endl;
        cout<<"地址是："<<abs->personArray[m].address<<endl;
        cout<<"性别是："<<abs->personArray[m].sex<<endl;
        cout<<"号码是："<<abs->personArray[m].number<<endl;
    }
}    

void rewritePerson(address_book *abs){
    string name;
    int m;
    cout<<"请输入您要修改的联系人："<<endl;
    cin >> name;
    m = detectPerson(abs,name);   
        if (m == -1)
    {
        cout<<"未找到联系人"<<endl;
    }else{
            cout<<"请输入修改后姓名："<<endl;
            string name;
            cin >>name ;
            abs->personArray[m].name = name; 
            cout<<"请输入修改后年龄：";
            int age;
            cin >>age;
            abs->personArray[m].age = age;
            cout<<"请输入修改后性别：";
            int sex;
            cin >>sex;
            abs->personArray[m].sex = sex;
            cout<<"请输入修改后地址：";
            string address;
            cin >>address;
            abs->personArray[m].address = address;
            cout<<"请输入修改后号码：";
            string number;
            cin >>number;
            abs->personArray[m].number = number;
    } 
}

void cleanPerson(address_book *abs){
    abs->len = 0;
    cout<<"联系人已清空"<<endl;
}
int main(){
       //初始画通讯录结构体变量
    address_book abs;
    abs.len = 0;
    int select = 0;
    while(1){
        showMenu();
        cin >>select;
        switch (select)
        {
        case 0:
            cout<<"欢迎下次使用"<<endl;
            system("pause");
            return 0;
        case 1:
            addPerson(&abs);
            break;
        case 2:
            showPerson(&abs);
            break;
        case 3:
        {
            string name;
            cin>>name;
            deletePerson(&abs,name);
        }//变成代码块，防止switch报错。
            break;
        case 4:
            findPerson(&abs);
            break;
        case 5:
            rewritePerson(&abs);
            break;
        case 6:  
            cleanPerson(&abs);
            break;      
        default:
            break;
        }
    }
    system("pause");
    return 0;
}