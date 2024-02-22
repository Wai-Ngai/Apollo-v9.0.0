#include<iostream>
#include<string>
#include<fstream>
#include"person/identity.h"
#include"person/student.h"
#include"person/teacher.h"
#include"person/manager.h"
// #include"common/orderFile.h"
#include"common/globalFile.h"


// 管理员菜单
void managerMenu(Identity * &manager)
{
    while (true)
    {
        // 管理员菜单
        manager->operMenu();
        

        // 将父类指针转换成子类指针，可以调用子类里其他接口
        Manager* man = (Manager *)manager;

        // 这里更好的一种转换方式
        // Manager* man = dynamic_cast<Manager *>(manager);
        // if(man != nullptr)
        // {
        //     .....
        // }
        
        int select = 0;
        std::cin >> select;

        if (select ==1)
        {
            // 添加账号
            std::cout << "添加账号" << std::endl;
            man->addPerson();
        }else if (select == 2)
        {
            std::cout << "查看账号" << std::endl;
            man->showPerson();
        }else if (select == 3)
        {
            std::cout << "查看机房" << std::endl;
            man->showComputer();
        }else if (select == 4)
        {
            std::cout << "清空预约" << std::endl;
            man->cleanFile();
        }else
        {
            delete manager;
            std::cout << "注销成功" << std::endl;
            system("pause");
            system("cls");
            return;
        }
    }
}

// 学生菜单
void studentMenu(Identity * &student)
{
    while (true)
    {
        student->operMenu();
        Student * stu = dynamic_cast<Student*>(student);
        if (stu != nullptr)
        {
            int select = 0;
            std::cin>>select;

            if (select == 1)
            {
                // 申请预约
                stu->applyOder();
            }
            else if (select == 2)
            {
                // 查看自身预约
                stu->showMyOder();
            }
            else if (select == 3)
            {
                // 查看所有预约
                stu->showAllOder();
            }
            else if (select == 4)
            {
                // 取消预约
                stu->cancelOder();
            }
            else
            {
                delete student;
                std::cout << "注销成功" << std::endl;
                system("pause");
                system("cls");
                return;
            }
        }
    }
}

// 教师菜单
void teacherMenu(Identity * &teacher)
{
    while (true)
    {
        teacher->operMenu();

        Teacher* tea = (Teacher*)teacher;
        int select=0;
        std::cin>>select;

        if (select ==1)
        {
            // 查看所有预约
            tea->showAllOder();
        }
        else if (select ==2)
        {
            // 审核预约
            tea->validOder();
        }
        else
        {
            delete teacher;
            std::cout << "注销成功" << std::endl;
            return;
        }
    }
}

// 登录功能
void LogIn(std::string fileName, int type)
{
    Identity * person = nullptr;

    std::ifstream ifs;
    ifs.open(fileName, std::ios::in);
    
    // 文件不存在的情况
    if (!ifs.is_open())
    {
        std::cout << "文件不存在" << std::endl;
        ifs.close();
        return;
    }
    
    int id = 0;
    std::string name;
    std::string pwd;

    if (type == 1)
    {
       // 学生登录
       std::cout << "请输入你的学号： " << std::endl;
       std::cin >> id;
    }else if (type ==2)
    {
        // 教师登录
        std::cout << "请输入你的教职工号： " << std::endl;
        std::cin >> id;
    }
    
    std::cout << "请输入用户名： " << std::endl;
    std::cin >> name;
    std::cout << "请输入密码： " << std::endl;
    std::cin >> pwd;

    if (type == 1)
    {
        // 学生登录验证
        int f_id;
        std::string f_name;
        std::string f_pwd;

        while (ifs >> f_id && ifs >> f_name && ifs >> f_pwd)
        {
            if (id == f_id && name == f_name && pwd == f_pwd)
            {
                std::cout << "学生验证登录成功！" << std::endl;
                system("pause");
                system("cls");

                person = new Student(id, name, pwd);
                studentMenu(person);
            }
            return;
        }
    }
    else if (type == 2)
    {
        // 教师登录验证
        int f_id;
        std::string f_name;
        std::string f_pwd;
        
        while (ifs >> f_id && ifs >> f_name && ifs >> f_pwd)
        {
            if (id == f_id && name == f_name && f_pwd == pwd)
            {
                std::cout << "教师验证登录成功！" << std::endl;
                system("pause");
                system("cls");

                person = new Teacher(id, name, pwd);
                teacherMenu(person);
            }    
        return;
        }  
    }
    else if (type == 3)
    {
        // 管理员登录验证
        std::string f_name;
        std::string f_pwd;

        while (ifs >> f_name && ifs >> f_pwd)
        {
            if (f_name == name && f_pwd == pwd)
            {
                std::cout << "验证登录成功！" << std::endl;
                system("pause");
                system("cls");
                
                // 创建管理员对象
                person = new Manager(name,pwd);
                // 进入管理员子菜单
                managerMenu(person);
            }
            return;
        }  
    }
    std::cout << "登录验证失败！" << std::endl;
    system("pause");
    system("cls");
    return;
}

int main(int argc, char const *argv[])
{
    int select =0;
    OrderFile of;
    while (true)
    {
        std::cout << "======================  欢迎来到传智播客机房预约系统  =====================" << std::endl;

        std::cout << std::endl << "请输入您的身份" << std::endl;

        std::cout << "\t\t -------------------------------\n";
        std::cout << "\t\t|                               |\n";
        std::cout << "\t\t|          1.学生代表           |\n";
        std::cout << "\t\t|                               |\n";
        std::cout << "\t\t|          2.老    师           |\n";
        std::cout << "\t\t|                               |\n";
        std::cout << "\t\t|          3.管 理 员           |\n";
        std::cout << "\t\t|                               |\n";
        std::cout << "\t\t|          0.退    出           |\n";
        std::cout << "\t\t|                               |\n";
        std::cout << "\t\t -------------------------------\n";

        std::cout << "输入您的选择: ";

        std::cin >> select;

        switch (select)
        {
        case 1:
            // 学生身份
            LogIn(STUDENT_FILE, 1);
            break;
        case 2:
            // 教师身份
            LogIn(TEACHER_FILE, 2);
            break;
        case 3:
            // 管理员身份
            LogIn(ADMIN_FILE, 3);
            break;
        case 0:
            std::cout << "欢迎下次使用" << std::endl;
            return 0;
            break;
        default:
            std::cout << " 输入有误，请重新选择！ " << std::endl;
            system("pause");
            system("cls");
            break;
        }
    }
    system("pause");
    return 0;
}
