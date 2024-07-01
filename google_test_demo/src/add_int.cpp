#include "add_int.h"

int add_int(int a, int b) {
  if (a > b)
  {
    a *= 10;
  }
  
  return a+b;
}