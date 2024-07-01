#include <iostream>

/**
 * @brief  目的： 测试类作为成员变量时，构造顺序
 * 
 */

class Member {
public:
    // Member() {
    //     std::cout << "Member constructed\n";
    // }
    Member() = delete;

    Member(int a) {
        std::cout << "Parametric construction\n";
        std::cout << "a = " << a << std::endl;
    }
     ~Member() {
        std::cout << "Member die" << std::endl;
    }
};

class MyClass {
public:  
    // MyClass() {
    //     std::cout << "MyClass constructed\n";
    //     m = Member(100);
    // }

    MyClass() : m(100){
        std::cout << "MyClass constructed\n";
    }
    ~MyClass() {
        std::cout << "MyClass die"<< std::endl;
    }

public:
    Member m; 
};

void test() {
    MyClass obj;
    for (size_t i = 0; i < 10; i++)
    {
       std::cout << "test function : " << i << std::endl;
    }
    
}

int main() {
    test();
    for (size_t i = 0; i < 10; i++)
    {
       std::cout << "main function : " << i << std::endl;
    }
    return 0;
}
