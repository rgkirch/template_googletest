#include "gtest/gtest.h"

#include <iostream>
#include "hello.cpp"

using namespace std;

TEST(hello, h) { ASSERT_EQ(hello(), 'h'); }
