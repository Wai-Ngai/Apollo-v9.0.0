#include"teacher.h"

Teacher::Teacher()
{
}

Teacher::Teacher(int empID, std::string name, std::string password)
{
    this->emp_id_ = empID;
    this->name_ = name;
    this->password_ = password;
}

void Teacher::operMenu()
{
    std::cout << "欢迎教师：" << this->name_ << "登录！" << std::endl;
    std::cout << "\t\t ----------------------------------\n";
    std::cout << "\t\t|                                  |\n";
    std::cout << "\t\t|          1.查看所有预约          |\n";
    std::cout << "\t\t|                                  |\n";
    std::cout << "\t\t|          2.审核预约              |\n";
    std::cout << "\t\t|                                  |\n";
    std::cout << "\t\t|          0.注销登录              |\n";
    std::cout << "\t\t|                                  |\n";
    std::cout << "\t\t ----------------------------------\n";
    std::cout << "请选择您的操作： " << std::endl;
}

void Teacher::showAllOder()
{
}

void Teacher::validOder()
{
}

Teacher::~Teacher()
{
}
