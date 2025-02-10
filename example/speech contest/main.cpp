#include <iostream>
#include <string>
using namespace std;
#include "speechManager.h"
#include<ctime>
int main()
{
    speechManager sm;

    int choice;

    while(true)
    {
        srand((unsigned int)time(NULL));
        sm.showMenu();
        cout<<"请输入您的选择：";
        cin>>choice;
        switch(choice)
        {
        case 1:
            sm.startspeech();
            break;
        case 2:
            sm.showRecord();
            break;
        case 3:
            sm.clearScore();
            break;
        case 0:
            sm.exitSpeech();
            break;
        default:
            cout<<"请输入正确选项";
            break;
        }
    }
    


    system("pause");
    return 0;
}