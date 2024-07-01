#include <iostream>

/**
 * @brief 当成员变量的构造函数有多个参数，或者这些参数本身是类对象时，
 * 我们仍然可以使用初始化列表来高效地初始化这些成员。
 * 初始化列表允许我们在构造函数体执行之前直接对成员进行初始化，从而避免了不必要的默认构造和赋值操作。
 * 
 */

class AnotherClass {
public:
    AnotherClass(int x) {
        std::cout << "AnotherClass constructed with x = " << x << std::endl;
    }
    ~AnotherClass() {
        std::cout << "AnotherClass die" << std::endl;
    }
};

class Member {
public:
    Member(int a, double b, const AnotherClass& ac) {
        std::cout << "Member constructed with a = " << a << ", b = " << b << std::endl;
    }
    ~Member() {
        std::cout << "Member die" << std::endl;
    }
};

class MyClass {
public:
    // 使用初始化列表初始化成员变量 m
    MyClass(int a, double b, int x) : m(a, b, AnotherClass(x)) {
        std::cout << "MyClass constructed\n"<< std::endl;
    }
    ~MyClass() {
        std::cout << "MyClass die"<< std::endl;
    }

private:
    Member m;
};

void test() {
    MyClass obj(1, 2.5, 10);
    for (size_t i = 0; i < 3; i++)
    {
       std::cout << "test function : " << i << std::endl;
    }
    
}

int main() {
    test();
    for (size_t i = 0; i < 3; i++)
    {
       std::cout << "main function : " << i << std::endl;
    }
    return 0;
}
