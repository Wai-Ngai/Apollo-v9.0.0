#include"student.h"

Student::Student()
{
}

Student::Student(int id, std::string name, std::string password)
{
    // 初始化属性
    this->stu_id_ = id;
    this->name_ = name;
    this->password_ = password;

    // 获取机房信息
    std::ifstream ifs;
    ifs.open(COMPUTER_FILE, std::ios::in);

    ComputerRoom c;
    while (ifs >> c.computer_id_ && ifs >> c.max_num_)
    {
        v_computer_room_.push_back(c);
    }
    ifs.close();
}

void Student::operMenu()
{
    std::cout << "欢迎学生代表：" << this->name_ << "登录！" << std::endl;
    std::cout << "\t\t ----------------------------------\n";
    std::cout << "\t\t|                                 |\n";
    std::cout << "\t\t|          1.申请预约              |\n";
    std::cout << "\t\t|                                 |\n";
    std::cout << "\t\t|          2.查看我的预约          |\n";
    std::cout << "\t\t|                                 |\n";
    std::cout << "\t\t|          3.查看所有预约          |\n";
    std::cout << "\t\t|                                 |\n";
    std::cout << "\t\t|          4.取消预约              |\n";
    std::cout << "\t\t|                                 |\n";
    std::cout << "\t\t|          0.注销登录              |\n";
    std::cout << "\t\t|                                 |\n";
    std::cout << "\t\t ----------------------------------\n";
    std::cout << "请选择您的操作： " << std::endl;
}

void Student::applyOder()
{
	std::cout << "机房开放时间为周一至周五！" << std::endl;
	std::cout << "请输入申请预约的时间：" << std::endl;
	std::cout << "1、周一" << std::endl;
	std::cout << "2、周二" << std::endl;
	std::cout << "3、周三" << std::endl;
	std::cout << "4、周四" << std::endl;
	std::cout << "5、周五" << std::endl;

    int date = 0;
    int interval = 0;
    int room = 0;

    while (true)
    {
        std::cin >> date;
        if (date >=1 && date <= 5)
        {
            break;
        }
        std::cout << "输入有误，请重新输入" << std::endl;
    }
    
    std::cout << "请输入申请预约的时间段：" << std::endl;
    std::cout << "1.上午" << std::endl;
    std::cout << "2.下午" << std::endl;
    
    while (true)
    {
        std::cin >> interval;
        if (interval >=1 && interval <=2)
        {
            break;
        }
        std::cout << "输入有误，请重新输入" << std::endl;
    }
    
    std::cout << "请选择机房： " << std::endl;
    std::cout << "1号机房容量： " << v_computer_room_[0].max_num_<< std::endl;
    std::cout << "2号机房容量： " << v_computer_room_[1].max_num_<< std::endl;
    std::cout << "3号机房容量： " << v_computer_room_[2].max_num_<< std::endl;

    while (true)
    {
        std::cin >> room;
        if(room >=1 && room <= 3)
        {
            break;
        }
        std::cout << "输入有误，请重新输入" << std::endl;
    }
    
    std::cout << "预约成功！ 审核中..." << std::endl;

    std::ofstream ofs(ORDER_FILE, std::ios::app);
    ofs << "date:" << date << " ";
    ofs << "interval:" << interval << " ";
    ofs << "stuID:" << this->stu_id_ << " ";
    ofs << "stuName:" << this->name_ << " ";
    ofs << "roomId:" << room << " ";
    ofs << "status:" << 1 << std::endl;

    ofs.close();

    system("pause");
    system("cls");
}

void Student::showMyOder()
{
    OrderFile of;
    if (of.size_ == 0)
    {
        std::cout << "无预约记录" << std::endl;
        system("pause");
        system("cls");
        return;
    }
    
    for (int i = 0; i < of.size_; i++)
    {
        if (atoi(of.m_order_date_[i]["stuId"].c_str()) == this->stu_id_)
        {
            std::cout << "预约日期：周"<< of.m_order_date_[i]["date"];
            std::cout << "  时段：" << (of.m_order_date_[i]["interval"] == "1"?"上午":"下午");
            std::cout << "  机房：" << of.m_order_date_[i]["roomId"];

            std::string status = "  状态： ";
            if (of.m_order_date_[i]["status"] == "1")
            {
                status += "审核中";
            }
            else if (of.m_order_date_[i]["status"] == "2")
            {
                status += "预约成功";
            }
            else if (of.m_order_date_[i]["status"] == "-1")
            {
                status += "审核未通过，预约失败";
            }
            else
            {
                status += "预约取消";
            }
            std::cout << status << std::endl;
        }
        
    }
    
}

void Student::showAllOder()
{
    OrderFile of;
    if (of.size_ == 0)
    {
        std::cout << "无预约记录" << std::endl;
        system("pause");
        system("cls");
        return;
    }
    
    for (int i = 0; i < of.size_; i++)
    {
        std::cout << i + 1 << "、";
        
        std::cout << "预约日期：周"<< of.m_order_date_[i]["date"];
        std::cout << "  时段：" << (of.m_order_date_[i]["interval"] == "1"?"上午":"下午");
        std::cout << "  学号：" << of.m_order_date_[i]["stuId"];
        std::cout << "  姓名：" << of.m_order_date_[i]["stuName"];
        std::cout << "  机房：" << of.m_order_date_[i]["roomId"];

        std::string status = "  状态： ";
        if (of.m_order_date_[i]["status"] == "1")
        {
            status += "审核中";
        }
        else if (of.m_order_date_[i]["status"] == "2")
        {
            status += "预约成功";
        }
        else if (of.m_order_date_[i]["status"] == "-1")
        {
            status += "审核未通过，预约失败";
        }
        else
        {
            status += "预约取消";
        }
        std::cout << status << std::endl;
    }
    system("pause");
    system("cls");
}

void Student::cancelOder()
{
    OrderFile of;
    if (of.size_ == 0)
    {
        std::cout << "无预约记录" << std::endl;
        system("pause");
        system("cls");
        return;
    }
    std::cout << "审核中预约成功的记录可以取消，请输入取消的记录" << std::endl;

    std::vector<int> v;
    int index = 1;
    for (int i = 0; i < of.size_; i++)
    {
        if (atoi(of.m_order_date_[i]["stuId"].c_str()) == this->stu_id_)
        {
            if (of.m_order_date_[i]["status"] == "1" || of.m_order_date_[i]["status"] == "2")
            {
                v.push_back(i);
                std::cout << index++ << "、";
                std::cout << "预约日期：周" << of.m_order_date_[i]["date"];
                std::cout << "  时段：" << (of.m_order_date_[i]["interval"] == "1"?"上午":"下午");
                std::cout << "  机房：" << of.m_order_date_[i]["roomId"];

                std::string status;
                if (of.m_order_date_[i]["status"] == "1")
                {
                    status += "审核中";
                }
                else if (of.m_order_date_[i]["status"] == "2")
                {
                    status += "预约成功";
                }
                std::cout << status << std::endl;
            }
            
        }
        
    }

    std::cout << "请输入取消的记录，0代表返回" << std::endl;
    int select = 0;

    while (true)
    {
        std::cin >> select;
        if (select >= 0 && select <= v.size())
        {
            if (select == 0)
            {
                break;
            }
            else
            {
                of.m_order_date_[v[select-1]]["status"] = "0";
                of.updateOrder();
                std::cout << "已取消预约" << std::endl;
                break;
            }
        }
        std::cout << "输入有误，请重新输入" << std::endl;
    }
}

Student::~Student()
{
}
