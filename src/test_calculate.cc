#include <gtest/gtest.h>

#include <iostream>

#include "calculate.h"

class TestCalculate : public ::testing::Test {
 public:
  Checks check;
};

TEST_F(TestCalculate, inputValidationTest) {
  // {"COS", !},  {"SIN", @},  {"TAN", #}, {"ACOS", $}, {"ASIN", _},
  //     {"ATAN", v}, {"SQRT", b}, {"LN", u},  {"LOG", p},  {"MOD", %}};
  EXPECT_EQ(check.check_input("12543"), 1);
  EXPECT_EQ(check.check_input("125^+43"), 0);
  EXPECT_EQ(check.check_input("12..5^43"), 0);
  EXPECT_EQ(check.check_input("12.543"), 1);
  EXPECT_EQ(check.check_input("12.543^"), 0);
  EXPECT_EQ(check.check_input("((2-1))"), 1);
  EXPECT_EQ(check.check_input("((2-1))1"), 0);
  EXPECT_EQ(check.check_input("((2-1))+1"), 1);
  EXPECT_EQ(check.check_input("12.543+((2-1))"), 1);
  EXPECT_EQ(check.check_input("12.543((2-1))"), 0);
}
