#include"speechManager.h"

SpeechManager::SpeechManager(/* args */)
{
    // 初始化属性
    this->initSpeech();
    // 创建选手
    this->createSpeaker();

    // 获取往届记录
    this->loadRecord();
}

SpeechManager::~SpeechManager()
{
}


void SpeechManager::showMenu()
{
    std::cout << "***************************************" << std::endl;
    std::cout << "***********    欢迎参加比赛  ************" << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "*************  1.开始比赛  **************" << std::endl;
    std::cout << "*************  2.查看比赛  **************" << std::endl;
    std::cout << "*************  3.清空比赛  **************" << std::endl;
    std::cout << "*************  0.退出比赛  **************" << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "***************************************" << std::endl;
}


void SpeechManager::exitSystem()
{
    std::cout << "欢迎下次使用" << std::endl;
    system("pause");
    exit(0);
}

void SpeechManager::initSpeech()
{
    // 保证容器为空
    this->v1.clear();
    this->v2.clear();
    this->v3.clear();
    this->speaker_map_.clear();

    // 初始化比赛轮数
    this->index_ = 1;

    this->record_.clear();
}

void SpeechManager::createSpeaker()
{
    std::string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameSeed.size(); i++)
    {
        std::string name = "选手";
        name += nameSeed[i];

        Speaker sp;
        sp.name_ = name;
        for (int j = 0; j < 2; j++)
        {
            sp.score_[j] = 0;
        }
        
        this->v1.push_back(i+10001);
        this->speaker_map_.insert(std::make_pair(i+10001,sp));
    }
}

void SpeechManager::startSpeech()
{
    // 开始比赛

    // 第一轮比赛
    // 抽签
    speechDraw();
    // 比赛
    speechContest();
    // 显示晋级结果
    showScore();
    // 第二轮比赛
    this->index_++;
    // 抽签
    speechDraw();
    // 比赛
    speechContest();
    // 显示最终结果
    showScore();
    // 保存分数
    saveRecord(); 

    std::cout << "本届比赛完毕" << std::endl;

    this->initSpeech();
    this->createSpeaker();
    this->loadRecord();

}

void SpeechManager::speechDraw()
{
    std::cout << "第" << this->index_ << "轮比赛选手正在抽签 "<< std::endl;
    std::cout << "------------------------------------" << std::endl;
    std::cout << "抽签后的演讲顺序如下： " << std::endl;

    if (this->index_ == 1)
    {
        random_shuffle(v1.begin(),v1.end());
        for (std::vector<int>::iterator it = v1.begin(); it != v1.end();it++)
        {
            std::cout << *it << std::endl;
        }
        std::cout << std::endl;
    }
    else
    {
        random_shuffle(v2.begin(), v2.end());
        for(std::vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
        {
            std::cout << *it << std::endl;
        }
        std::cout << std::endl;
    }
    
    std::cout << "------------------------------------" << std::endl;
    system("pause");
    std::cout << std::endl;
}


void SpeechManager::speechContest()
{
    std::cout << "第" << this->index_<< "轮选手比赛开始：" << std::endl;
    std::cout << "------------------------------------" << std::endl;
 
    std::multimap<double, int, std::greater<int>> groupScore; // 临时容器
    int num = 0;                          // 记录人员数
    std::vector<int> v_src;               // 比赛人员容器

    if (this->index_ ==1)
    {
        v_src = v1;
    }else
    {
        v_src = v2;
    }
    
    // 遍历所有参赛选手
    for(std::vector<int>::iterator it = v_src.begin(); it != v_src.end(); it++)
    {
        num++;

        // 评委打分
        std::deque<double> d;
        for (int i = 0; i < 10; i++)
        {
            double score = (rand() % 401 + 600)/ 10.f;
            d.push_back(score);
        }
        sort(d.begin(),d.end(),std::greater<double>());
        d.pop_front();  // 去掉一个最高分
        d.pop_back();   // 去掉一个最低分

        double sum = accumulate(d.begin(), d.end(), 0.0f);
        double avg = sum/(double)d.size();

        this->speaker_map_[*it].score_[this->index_-1] = avg;

        groupScore.insert(std::make_pair(avg, *it));
        if (num % 6 == 0)
        {
            std::cout << "第" << num/6 << "组比赛名次：" << std::endl;
            for (std::multimap<double,int,std::greater<int>>::iterator it = groupScore.begin(); it != groupScore.end();it++)
            {
                std::cout << "编号： " << it->second << "  姓名：" << this->speaker_map_[it->second].name_
                << " 成绩：" << this->speaker_map_[it->second].score_[this->index_ -1] << std::endl;
            }
            
            int count = 0;
            for(std::multimap<double,int, std::greater<int>>::iterator it = groupScore.begin();it != groupScore.end()&& count < 3;it++,count++)
            {
                if (this->index_ == 1)
                {
                    v2.push_back((*it).second);
                }
                else
                {
                    v3.push_back((*it).second);
                }
            }
            groupScore.clear();
            std::cout << std::endl;
        }
    }
    std::cout << "------------- 第" << this->index_ << "轮比赛完毕  ----------"<<std::endl;
}


void SpeechManager::showScore()
{
    std::cout << "第" << this->index_ << "轮晋级的选手信息如下："<< std::endl;
    std::vector<int> v_temp;
    if (this->index_ == 1)
    {
        v_temp = v2;
    }else
    {
        v_temp = v3;
    }
    
    for(std::vector<int>::iterator it = v_temp.begin(); it != v_temp.end(); it++)
    {
        std::cout << "选手编号： " << *it << "  姓名：" << speaker_map_[*it].name_
        << "  得分："<< speaker_map_[*it].score_[this->index_-1] << std::endl;
    }
    std::cout << std::endl;
    system("pause");
    system("cls");
    this->showMenu();
}

void SpeechManager::saveRecord()
{
    std::ofstream ofs;
    ofs.open("speech.csv", std::ios::out|std::ios::app);
    
    for(std::vector<int>::iterator it = v3.begin(); it != v3.end();it++)
    {
        ofs << *it<< ","<<speaker_map_[*it].score_[1]<< ",";
    }
    ofs<< std::endl;
    ofs.close();

    std::cout << "记录已经保存完毕" << std::endl;
    this->fileIsEmpty_ = false;
}


void SpeechManager::loadRecord()
{
    std::ifstream ifs("speech.csv",std::ios::in);
    
    if (!ifs.is_open())
    {
        this->fileIsEmpty_ = true;
        std::cout << "文件不存在" << std::endl;
        ifs.close();
        return;
    }
    
    char ch;
    ifs>>ch;
    if (ifs.eof())  // 先读取一个字符，判断是否读取到文件尾
    {
        std::cout << "文件为空" << std::endl;
        this->fileIsEmpty_ = true;
        ifs.close();
        return;
    }

    this->fileIsEmpty_ = false;

    ifs.putback(ch);  // 读取的单个字符放回去

    std::string data;
    int index = 0;

    while (ifs>>data)   // 一行一行读取
    {
        std::vector<std::string> v;
        int pos = -1;
        int start = 0;

        while (true)
        {
            pos = data.find(",",start); //从0开始查找 ','
            if (pos == -1)
            {
                break;
            }
            //找到了,进行分割 参数1 起始位置，参数2 截取长度
            std::string temp = data.substr(start,pos-start);

            v.push_back(temp);
            start = pos +1;
        }
        this->record_.insert(std::make_pair(index,v));
        index++;
    }
    ifs.close();
}

void SpeechManager::showRecord()
{
    if (this->fileIsEmpty_)
    {
        std::cout << "文件不存在，或记录为空" << std::endl;
    }
    else
    {
        for (int i = 0; i < this->record_.size(); i++)
        {
            std::cout << "第" << i+1<< "届" <<
            "冠军编号： "<< this->record_[i][0] << "   得分： " << this->record_[i][1] << "  "
            "亚军编号： "<< this->record_[i][2] << "   得分： " << this->record_[i][3] << "  "
            "季军编号： "<< this->record_[i][4] << "   得分： " << this->record_[i][5] << "  "
            << std::endl;
        }
    }
}



