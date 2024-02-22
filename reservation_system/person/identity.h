#pragma once
#include <string>


// 身份抽象类
class Identity
{
private:
    /* data */
public:
    virtual void operMenu() = 0;

    std::string name_;
    std::string password_;
};
