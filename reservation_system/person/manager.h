#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

#include "identity.h"
#include "student.h"
#include "teacher.h"
#include "../common/globalFile.h"
#include "../common/computerRoom.h"

class Manager:public Identity
{
private:
    /* data */
public:
    Manager(/* args */);

    Manager(std::string name, std::string password);

    // 选择菜单
    void operMenu();

    // 添加账号
    void addPerson();

    // 查看账号
    void showPerson();

    // 查看机房信息
    void showComputer();

    // 清空预约记录
    void cleanFile();
    
    // 初始化容器
    void initVector();

    // 检测重复
    bool checkRepeat(int id, int type);

    ~Manager();
public:
    // 学生容器
    std::vector<Student> v_student_;
    // 老师容器
    std::vector<Teacher> v_teacher_;
    // 机房信息容器
    std::vector<ComputerRoom> v_computer;
};
