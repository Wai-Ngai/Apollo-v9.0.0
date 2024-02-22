#include "orderFile.h"

OrderFile::OrderFile()
{
    std::ifstream ifs;
    ifs.open(ORDER_FILE, std::ios::in);

    std::string date;
    std::string interval;
    std::string stuId;
    std::string stuName;
    std::string roomId;
    std::string status;

    this->size_ = 0;
    while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName
        && ifs >> roomId && ifs >> status)
    {
        // std::cout << date << std::endl;
        // std::cout << interval << std::endl;
        // std::cout << stuId << std::endl;
        // std::cout << stuName << std::endl;
        // std::cout << roomId << std::endl;
        // std::cout << status << std::endl;

        std::string key;
        std::string value;
        std::map<std::string, std::string> m;

        int pos = date.find(":");
        if (pos != -1)
        {
            key = date.substr(0,pos);
            value = date.substr(pos+1, date.size()-pos-1);
            m.insert(std::make_pair(key,value));
        }
        
        pos = interval.find(":");
        if (pos != -1)
        {
            key = interval.substr(0,pos);
            value = interval.substr(pos+1,interval.size()-pos-1);
            m.insert(std::make_pair(key,value));
        }
        
        pos = stuId.find(":");
        if (pos != -1)
        {
            key = stuId.substr(0,pos);
            value = stuId.substr(pos+1,stuId.size()-pos-1);
            m.insert(std::make_pair(key,value));
        }
        
        pos = stuName.find(":");
        if (pos != -1)
        {
            key = stuName.substr(0,pos);
            value = stuName.substr(pos+1,stuName.size()-pos-1);
            m.insert(std::make_pair(key,value));
        }

        pos = roomId.find(":");
        if (pos != -1)
        {
            key = roomId.substr(0,pos);
            value = roomId.substr(pos+1,roomId.size()-pos-1);
            m.insert(std::make_pair(key,value));
        }

        pos = status.find(":");
        if (pos != -1)
        {
            key = status.substr(0,pos);
            value = status.substr(pos+1,status.size()-pos-1);
            m.insert(std::make_pair(key,value));
        }

        this->m_order_date_.insert(std::make_pair(this->size_,m));
        this->size_++;

    }
    ifs.close();
}

OrderFile::~OrderFile()
{
}

void OrderFile::updateOrder()
{
    if (this->size_ == 0)
    {
        return;
    }

    std::ofstream ofs(ORDER_FILE, std::ios::in | std::ios::trunc);
    for (int i = 0; i < size_; i++)
    {
        ofs << "date:" << this->m_order_date_[i]["date"]<<"  ";
        ofs << "interval:" << this->m_order_date_[i]["interval"]<<"  ";
        ofs << "stuId:" << this->m_order_date_[i]["stuId"]<<"  ";
        ofs << "stuName:" << this->m_order_date_[i]["stuName"]<<"  ";
        ofs << "roomId:" << this->m_order_date_[i]["roomId"]<<"  ";
        ofs << "status:" << this->m_order_date_[i]["status"]<<"  ";
    }
    ofs.close();
}