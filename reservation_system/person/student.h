#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "identity.h"
#include "../common/computerRoom.h"
#include "../common/globalFile.h"
#include "../common/orderFile.h"

class Student : public Identity
{
private:
    /* data */
public:
    Student();

    // 有参构造
    Student(int id,std::string name, std::string password);

    // 菜单界面
    virtual void operMenu();

    // 申请预约
    void applyOder();

    // 查看我的预约
    void showMyOder();

    // 查看所有预约
    void showAllOder();

    // 取消预约
    void cancelOder();


    ~Student();
public:
    // 学号
    int stu_id_;
    // 机房容器
    std::vector<ComputerRoom> v_computer_room_;
};

