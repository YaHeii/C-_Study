#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <map>
#include "speaker.h"

class speechManager
{
public:
    //构造函数
    speechManager();
    //菜单函数
    void showMenu(); 
    //初始化
    void initSpeech();
    //创建选手
    void createSpeaker();
    //抽签
    void speechDraw();
    //比赛函数
    void speechContest();
    //比赛流程
    void startspeech();
    //显示比赛记录
    void showRecord();
    //保存分数
    void saveScore();
    //读取分数
    void loadRecord();
    //清空分数
    void clearScore();
    //退出
    void exitSpeech();
    //析构函数
    ~speechManager();


    //成员属性
    //第一轮选手编号 12
    vector<int> v1;
    //第二轮选手编号 6
    vector<int> v2;
    //第三轮选手编号 3
    vector<int> vect;
    //存放选手信息
    map<int,speaker> m_speaker;
    //存放往届选手
    map<int,vector<string>>m_record;
    //记录轮数
    int index;
};