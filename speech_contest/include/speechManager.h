#pragma once

#include<iostream>
#include<vector>
#include<map>
#include<deque>
#include<string>
#include<algorithm>
#include<numeric>
#include<fstream>
#include"speaker.h"

class SpeechManager
{
private:
    /* data */
public:
    SpeechManager(/* args */);

    ~SpeechManager();

    void showMenu();

    void exitSystem();

    void initSpeech();

    void createSpeaker();

    void startSpeech();

    void speechDraw();

    void speechContest();

    void showScore();

    void saveRecord();

    void loadRecord();

    void showRecord();

public:
    // 比赛选手容器  12人
    std::vector<int> v1;

    // 第一轮晋级  6人
    std::vector<int> v2;

    // 前三名   3人
    std::vector<int> v3;

    // 存放编号 以及对应的具体选手容器
    std::map<int, Speaker> speaker_map_;

    int index_;
    bool fileIsEmpty_;

    std::map<int, std::vector<std::string>> record_;
};
