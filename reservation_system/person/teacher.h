#pragma once
#include<iostream>
#include"identity.h"

class Teacher: public Identity
{
private:
    /* data */
public:
    Teacher(/* args */);

    Teacher(int empID, std::string name, std::string password);

    // 菜单界面
    virtual void operMenu();

    // 查看所有预约
    void showAllOder();

    // 审核预约
    void validOder();

    ~Teacher();
    
public:
    int emp_id_;
};

