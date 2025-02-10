#include<iostream>
#include "speechManager.h"
using namespace std;
#include <string>
#include "speaker.h"
#include <deque>
#include <algorithm>
#include <vector>
#include <numeric>
#include <fstream>

speechManager::speechManager()
{
    initSpeech();
    createSpeaker();
}

void speechManager::showMenu()
{
    cout<<"**********欢迎参加演讲比赛**********"<<endl;
    cout<<"**********1.开始演讲比赛************"<<endl;
    cout<<"**********2.查看往届比赛记录********"<<endl;
    cout<<"**********3.清空比赛记录************"<<endl;
    cout<<"**********0.退出比赛程序************"<<endl;

}
void speechManager::exitSpeech()
{
    cout <<"欢迎下次使用"<<endl;
    system("pause");
    exit(0);
}
void speechManager::initSpeech()
{
    //容器置空
    this->v1.clear();
    this->v2.clear();
    this->vect.clear();
    this->m_speaker.clear();
    this->m_record.clear();
    //初始化比赛轮数
    index = 1;
}
void speechManager::createSpeaker()
{
    string nameSeed = "ABCDEFGHIJKL";
    for(int i = 0;i<nameSeed.size();i++)
    {
        string name = "选手";
        name += nameSeed[i];
        //创建选手
        speaker sp;
        sp.m_name = name;
        for(int j = 0;j<2;j++)
        {
            sp.m_score[j] = 0;
        }
        //创建编号
        int num = i + 1001;
        //放入第一轮容器
        v1.push_back(num);
        //放入map容器
        m_speaker.insert(make_pair(num,sp));
    }
}

void speechManager::speechDraw()
{
    cout<<"第"<<this->index<<"轮比赛选手"<<endl;
    cout<<"---------------------------"<<endl;
    cout<<"演讲顺序如下："<<endl;
    if(this->index == 1)
    {
        random_shuffle(v1.begin(),v1.end());
        for(vector<int>::iterator it = v1.begin();it != v1.end();it++)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    }else{
        random_shuffle(v2.begin(),v2.end());
        for(vector<int>::iterator it = v2.begin();it != v2.end();it++)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    }

}

void speechManager::speechContest()
{
    cout<<"第"<<index<<"轮比赛开始"<<endl;

    int num = 0;//计数
    multimap<double,int,greater<double>> groupSource;//分成6人两组
    vector<int> src;
    if(index == 1){
        src = v1;
    }else{
        src = v2;
    }
    for(vector<int>::iterator it = src.begin();it != src.end();it++)
    {
        cout<<*it<<"号选手正在演讲"<<endl;
        //随机生成选手分数
        deque<double> d;
        for(int i = 0;i<10;i++)
        {
            double score = (rand()%401+600)/10.0;
            d.push_back(score);
        }
        sort(d.begin(),d.end());//排序
        d.pop_back();//去除最高最低
        d.pop_front();
        double avg = accumulate(d.begin(),d.end(),0.0f)/(double)d.size();//平均分
        //保存选手分数
        this->m_speaker[*it].m_score[index-1] = avg;
        //打印平均份
        cout<<"编号："<<*it<<"姓名："<<this->m_speaker[*it].m_name<<"分数："<<avg<<endl;

        groupSource.insert(make_pair(avg,*it));
        num++;
        if(num%6 == 0)
        {
            cout<<"第"<<num/6<<"小组比赛结束"<<endl;
            cout<<"选手名次如下："<<endl;
            for(multimap<double,int,greater<double>>::iterator it = groupSource.begin();it != groupSource.end();it++)
            {
                cout<<"编号："<<it->second<<"姓名"<<this->m_speaker[it->second].m_name<<"成绩是："
                <<this->m_speaker[it->second].m_score[index-1]<<endl;
            }
            cout<<"---------------------------"<<endl;
            int count = 0;
            for(multimap<double,int,greater<double>>::iterator it = groupSource.begin();it != groupSource.end() && count<3;it++,count++)
            {
                if(index ==1)
                    {
                        v2.push_back(it->second);
                    }else{
                        vect.push_back(it->second);
                    }
            }

            groupSource.clear();
        }
    }
    cout<<"第"<<index<<"轮比赛结束"<<endl;
}

void speechManager::startspeech()
{
    //抽签
    speechDraw();
    //第一轮比赛
    cout<<"比赛开始"<<endl;
    speechContest();
    //第二轮比赛
    this->index++;
    speechDraw();
    speechContest();
    //第二轮比赛结果输出
    cout<<"前三名为："<<endl;
    for(vector<int>::iterator it = vect.begin();it != vect.end();it++)
    {
        cout<<"编号："<<*it<<"姓名"<<m_speaker[*it].m_name<<"成绩是："<<m_speaker[*it].m_score[1]<<endl;
    }
    saveScore();

}

void speechManager::saveScore()
{
    ofstream ofs;
    ofs.open("speech.csv",ios::out | ios::app);//写文件，追加式

    for(vector<int>::iterator it = vect.begin();it != vect.end();it++)
    {
        ofs<<*it<<","<<m_speaker[*it].m_score[1]<<",";
    }
    ofs<<endl;
    ofs.close();
    cout<<"保存成功"<<endl;
}
void speechManager::loadRecord()
{
    ifstream ifs;
    ifs.open("example/speech contest/speech.csv",ios::in);
    if(!ifs.is_open())
    {
        cout<<"文件打开失败"<<endl;
        ifs.close();
        return;
    }
    // string ch;
    // ifs>>ch;
    // if(ifs.eof())
    // {
    //     cout<<"文件为空"<<endl;
    //     ifs.close();
    //     return;
    // }
    // //文件不为空
    // ifs.putback(ch);
    string data;
    int index = 0;
    while(ifs>>data)
    {
        vector<string> v;//存放字符串
        //cout<<data<<endl;
        int start = 0;
        int pos = -1;
        while (true)
        {
            pos = data.find(",",start);
            string temp = data.substr(start,pos-start);
            start = pos + 1; 
            v.push_back(temp);
            //cout<<temp<<endl;
            if(pos == -1)
            {
                break;
            }
        }

        this->m_record.insert(make_pair(index++,v));
        index++;

    }
    ifs.close();
    // for(map<int,vector<string>>::iterator it = m_record.begin();it != m_record.end();it++)
    // {
    //     for(map<int,vector<string>>::iterator it = m_record.begin();it != m_record.end();it++)
    //     {
    //         cout<<it->first<<"冠军选手编号"<<it->second[0]<<"分数："<<it->second[1]<<endl;
    //     }
    // }
}
void speechManager::showRecord()
{
    loadRecord();
    for (int i = 0;i<this->m_record.size();i++)
    {
        cout<<"第"<<i+1<<"届比赛"<<endl;
        cout<<"冠军编号："<<m_record[i][0]<<"分数："<<m_record[i][1]<<endl;
        cout<<"亚军编号："<<m_record[i][2]<<"分数："<<m_record[i][3]<<endl;
        cout<<"季军编号："<<m_record[i][4]<<"分数："<<m_record[i][5]<<endl;
        cout<<"---------------------------"<<endl;
    }
}
void speechManager::clearScore()
{
    cout<<"确定清空比赛记录吗？"<<endl;
    cout<<"1.确定"<<endl;
    cout<<"2.返回"<<endl;
    int choice;
    cin>>choice;
    if(choice == 1)
    {
        ofstream ofs;
        ofs.open("speech.csv",ios::trunc);
        ofs.close();
        this->initSpeech();
        cout<<"比赛记录已清空"<<endl;
    }else{
        return;
    }
}
speechManager::~speechManager()
{

}
