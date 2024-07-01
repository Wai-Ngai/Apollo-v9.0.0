#include <iostream>
#include <memory>
#include <cassert>

int main(int argc, char const *argv[]) {
  std::unique_ptr<int> uptr {new int(10)};
  std::cout << "uptr = " << *uptr << std::endl;


  std::unique_ptr<int> uptr1(new int(100));                 // 使用 new 分配一个整数并将其初始化为 100
  std::unique_ptr<int> uptr2 = std::make_unique<int>(100);  // 使用 std::make_unique 分配并初始化一个整数为 100

  std::cout << "uptr1 = " << *uptr1 << ",  uptr2 = " << *uptr2 << std::endl;

  std::unique_ptr<int> uptr3 = std::move(uptr1);

  std::cout << "uptr3 = " << *uptr3 << std::endl;

  assert(uptr1 == nullptr);

  std::unique_ptr<int> uptr4(uptr2.release());
  // *uptr4 = 1000;

  std::cout << "uptr4 = " << *uptr4 << std::endl;

  return 0;
}

// g++ -std=c++14 your_file.cpp -o your_program
