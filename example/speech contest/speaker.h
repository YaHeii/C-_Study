#pragma once
#include <iostream>
using namespace std;
#include <string>

class speaker
{
public:
    speaker();
    ~speaker();
    string m_name;
    double m_score[2];//最多两轮得分
};

