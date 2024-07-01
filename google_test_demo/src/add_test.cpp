#include "add_int.h"

#include "gtest/gtest.h"

TEST(AddTest, INT_VALUE) {
  EXPECT_EQ(add_int(1,2), 3);
  EXPECT_EQ(add_int(-1,2), 1);
  EXPECT_EQ(add_int(1,-2), 7);
}

TEST(AddTest, FLOAT_VALUE) {
  EXPECT_EQ(add_int(10.1, 10.2), 20);
}