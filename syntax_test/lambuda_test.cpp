#include <iostream>

int main(int argc, char const *argv[]) {
  int a = 10;

  auto result = [a]() -> int {
    std::cout << "int lambuda" << std::endl;
    return a + 10;
  }();

  std::cout << "int main, result = " << result << std::endl;

  return 0;
}
