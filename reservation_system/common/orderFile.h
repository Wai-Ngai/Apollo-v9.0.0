#pragma once

#include<iostream>
#include<map>
#include<fstream>
#include"globalFile.h"

class OrderFile
{
private:
    /* data */
public:
    OrderFile();
    ~OrderFile();

    // 更新预约记录
    void updateOrder();
public:
    // 记录容器
    std::map<int, std::map<std::string, std::string>> m_order_date_;
    // 预约记录条数
    int size_;
};
