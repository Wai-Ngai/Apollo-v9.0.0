#include"manager.h"

Manager::Manager()
{
}

Manager::Manager(std::string name, std::string password)
{
    this->name_ = name;
    this->password_ = password;

    // 初始化容器
    this->initVector();

    std::ifstream ifs;
    ifs.open(COMPUTER_FILE, std::ios::in);

    ComputerRoom c;
    while (ifs>>c.computer_id_ && ifs>>c.max_num_)
    {
        v_computer.push_back(c);
    }
    std::cout << "当前机房数量为： " << std::endl;
    ifs.close();
}

void Manager::operMenu()
{
        std::cout << "欢迎管理员："<<this->name_ << "登录！" << std::endl;
        std::cout << "\t\t ---------------------------------\n";
        std::cout << "\t\t|                                |\n";
        std::cout << "\t\t|          1.添加账号            |\n";
        std::cout << "\t\t|                                |\n";
        std::cout << "\t\t|          2.查看账号            |\n";
        std::cout << "\t\t|                                |\n";
        std::cout << "\t\t|          3.查看机房            |\n";
        std::cout << "\t\t|                                |\n";
        std::cout << "\t\t|          4.清空预约            |\n";
        std::cout << "\t\t|                                |\n";
        std::cout << "\t\t|          0.注销登录            |\n";
        std::cout << "\t\t|                                |\n";
        std::cout << "\t\t ---------------------------------\n";
        std::cout << "请选择您的操作： " << std::endl;
}

void Manager::addPerson()
{
    std::cout << "请输入添加账号的类型： " << std::endl;
    std::cout << "1.添加学生" << std::endl;
    std::cout << "2.添加老师" << std::endl;

    std::string file_name;
    std::string tip;
    std::string errorTip;
    std::ofstream ofs;
    int select = 0;
    
    std::cin >> select;

    if (select == 1)
    {
        file_name = STUDENT_FILE;
        tip = "请输入学号： ";
        errorTip = "学号重复，请重新输入";
    }
    else
    {
        file_name = TEACHER_FILE;
        tip = "请输入教职工号： ";
        errorTip = "职工号重复，请重新输入";
    }
    
    ofs.open(file_name, std::ios::out | std::ios::app);
    int id;
    std::string name;
    std::string pwd;

    std::cout << tip << std::endl;
    while (true)
    {
        std::cin >> id;
        bool ret = this->checkRepeat(id, select);
        if (ret)
        {
            std::cout << errorTip << std::endl;
        }
        else
        {
            break;
        }
    }
    


    std::cout << "请输入姓名： " << std::endl;
    std::cin >> name;
    std::cout << "请输入密码： " << std::endl;

    std::cin >> pwd;

    ofs << std::endl;
    ofs << id << " " << name << " " << pwd << " " << std::endl;
    std::cout << "添加成功" << std::endl;

    system("pause");
    system("cls");
    ofs.close();
    this->initVector();
}

void printStudent(Student &s)
{
    std::cout << "学号：" << s.stu_id_ << "  姓名：" << s.name_ << " 密码：" << s.password_<< std::endl;
}

void printTeacher(Teacher &t)
{
    std::cout << "职工号：" << t.emp_id_<< "  姓名：" << t.name_ << " 密码：" << t.password_<< std::endl;
}

void Manager::showPerson()
{
    std::cout << "请选择要查看的内容： " << std::endl;
    std::cout << "1.查看所有学生 " << std::endl;
    std::cout << "2.查看所有老师 " << std::endl;

    int select = 0;
    std::cin>>select;

    if (select == 1)
    {
        std::cout << "所有学生信息如下： " << std::endl;
        std::for_each(v_student_.begin(),v_student_.end(),printStudent);
    }
    else
    {
        std::cout << "所有老师信息如下： " << std::endl;
        std::for_each(v_teacher_.begin(),v_teacher_.end(),printTeacher);
    }
    system("pause");
    system("cls");
}

void Manager::showComputer()
{
    std::cout << "机房信息如下： " << std::endl;
    for (std::vector<ComputerRoom>::iterator it = v_computer.begin();it != v_computer.end(); it++)
    {
        std::cout << "机房编号： " << it->computer_id_ << "  机房最大容量： " << it->max_num_ << std::endl;
    }
    system("pause");
    system("cls");
}

void Manager::cleanFile()
{
    std::ofstream ofs(ORDER_FILE, std::ios::trunc);
    ofs.close();

    std::cout << "清空成功！" << std::endl;
    system("pause");
    system("cls");
}

void Manager::initVector()
{
    // 读取学生文件中的信息
    std::ifstream ifs;
    ifs.open(STUDENT_FILE, std::ios::in);
    if (!ifs.is_open())
    {
        std::cout << "文件读取失败！" << std::endl;
        return;
    }
    
    v_student_.clear();
    v_teacher_.clear();

    Student stu;
    while (ifs >> stu.stu_id_ && ifs >> stu.name_ && ifs >> stu.password_)
    {
        v_student_.push_back(stu);
    }
    std::cout << "学生的数量为：" << v_student_.size() << std::endl;
    ifs.close();

    // 读取老师信息
    ifs.open(TEACHER_FILE, std::ios::in);
    Teacher tec;
    while (ifs>>tec.emp_id_ && ifs >> tec.name_ && ifs >> tec.password_)
    {
        v_teacher_.push_back(tec);
    }
    std::cout << "教师的数量为：" << v_teacher_.size() << std::endl;
    ifs.close();
}

bool Manager::checkRepeat(int id, int type)
{
    if (type == 1)
    {
        for (std::vector<Student>::iterator it = v_student_.begin(); it != v_student_.end(); it++)
        {
            if (id == it->stu_id_)
            {
                return true;
            }
        }
    }
    else
    {
        for (std::vector<Teacher>::iterator it = v_teacher_.begin(); it != v_teacher_.end(); it++)
        {
            if (id == it->emp_id_)
            {
                return true;
            }
        }
    }
}

Manager::~Manager()
{
}
