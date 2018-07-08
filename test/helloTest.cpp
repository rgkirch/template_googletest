#include "gtest/gtest.h"

#include "hello.cpp"
#include <iostream>

using namespace std;

TEST(hello, h) {
  try {
    IO<string> io = readFile("testFile.txt", ReadMode());
    Either<string, string> e = io.unsafePerformIO();
    ASSERT_EQ(e.b, "this is test text");
  } catch (...) {
    cout << "catching all errors?" << endl;
  }
  //   string s = "";
}
