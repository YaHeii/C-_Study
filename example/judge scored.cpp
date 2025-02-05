#include<iostream>
#include<string>
using namespace std;
#include <vector>
#include <algorithm>    
#include <deque>

class person
{
public:
    person(string name, int score)
    {
        this->m_Name = name;
        this->m_Score = score;
    }
    string m_Name;
    int m_Score;
};
void setscore(person p)
{
    deque<int> d1;
    for (int i = 0; i < 3; i++)
    {
        int score  = rand()%41 + 60;//60-100
        cout<<p.m_Name<<"的第"<<i+1<<"个评委打分为："<<score<<endl;
        d1.push_back(score);
    }
    //排序
    sort(d1.begin(), d1.end());
    //去除最高分和最低分
    d1.pop_back();
    d1.pop_front();
    int sum = 0;
    for (deque<int>::iterator it = d1.begin(); it != d1.end(); it++)
    {
        sum += *it;
    }
    cout << p.m_Name << "的总分是：" << sum << endl;
    int avg = sum / d1.size();
    cout << p.m_Name << "的平均分是：" << avg << endl;

    p.m_Score = avg;
}


int main(){
    person p1("aaa", 0);
    person p2("bbb", 0);
    person p3("ccc", 0);
    vector<person> v1;
    v1.push_back(p1);
    v1.push_back(p2);
    v1.push_back(p3);
    for (vector<person>::iterator it = v1.begin(); it != v1.end(); it++)
    {
        cout << "Name: " << it->m_Name << " Score: " << it->m_Score << endl;
    }
    cout<<"选手已经存入vector容器"<<endl;
    //给选手打分
    setscore(p1);
    setscore(p2);
    setscore(p3);
    system("pause");
    return 0;
}