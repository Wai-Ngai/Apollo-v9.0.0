#include<iostream>
#include<ctime>
#include"speechManager.h"

 
int main()
{
    std::cout << "begin-----" << std::endl;
    srand((unsigned)time(NULL));

    SpeechManager sm;

    // for(std::map<int, Speaker>::iterator it = sm.speaker_map_.begin(); it != sm.speaker_map_.end(); ++it)
    // {
    //     std::cout << "选手编号： " << it->first << " 选手姓名： " << it->second.name_<<" 选手分数： "<< it->second.score_[0] << std::endl;
    // }

    int choice = 0;

    while (true)
    {
        sm.showMenu();

        std::cout << "请输入你的选择：" << std::endl;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            sm.startSpeech();
            break;
        case 2:
            sm.showRecord();
            break;
        case 3:
            break;
        case 0:
            sm.exitSystem();
            break;    
        default:
            system("cls");
            break;
        }
    }
    
    std::cout << "end-----" << std::endl;
    return 0;
}