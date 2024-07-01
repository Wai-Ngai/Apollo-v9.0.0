#include <string>

#include "student.h"

#include "gtest/gtest.h"

class StudentTest : public ::testing::Test {
 protected:
  void SetUp() override { student = new Student(1234, "Tom"); }
  void TearDown() override { delete student; }
  Student* student;
};


TEST_F(StudentTest, SET_AGE_TEST) {
  student->SetAge(16);
  int age = student->GetAge();
  EXPECT_EQ(age, 16);
}
TEST_F(StudentTest, SET_SCORE_TEST) {
  student->SetScore(99);
  int score = student->GetScore();
  ASSERT_EQ(score, 99);
}