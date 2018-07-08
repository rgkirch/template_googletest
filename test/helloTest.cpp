#include "gtest/gtest.h"

#include "hello.cpp"
#include <iostream>

using namespace std;

TEST(hello, h) {
  IO<string> io = readFile("testFile.txt", ReadMode());
  Either<string, string> e = io.unsafePerformIO();
  //   string s = "";
  ASSERT_EQ(e.b, "this is test text");
}
