#include <functional>
#include <iostream>
#include <string>

using namespace std;

struct IOException : public runtime_error {
  explicit IOException() : runtime_error(string("IO. I can't even.")){};
  virtual ~IOException() = default;
  // const char *what() const throw() { return "IO. I can't even."; }
};

struct IOMode {
  const char *modeChar;
};
struct ReadMode : public IOMode {
  const char *modeChar = "r";
};
struct WriteMode : public IOMode {
  const char *modeChar = "w";
};
struct AppendMode : public IOMode {
  const char *modeChar = "a";
};

template <typename A, typename B> struct Either {
  A a;
  B b;
};

template <typename A, typename B> auto left(A a) -> Either<A, B> {
  Either<A, B> e;
  e.a = a;
  return e;
}

template <typename A, typename B> auto right(B b) -> Either<A, B> {
  Either<A, B> e;
  e.b = b;
  return e;
}

template <typename A> struct IO {
  explicit IO(function<A()> a) : a(a) {}
  Either<string, A> unsafePerformIO() {
    try {
      return right<string, A>(a());
    } catch (...) {
      return left<string, string>("something bad");
    }
  }
  template <typename B> IO<B> map(function<B(A)> b) const {
    return IO([=]() { return b(a()); });
  }
  function<A()> a;
};

struct Vec3 {
  double x;
  double y;
  double z;
};

typedef Vec3 Stl[3];

IO<string> readFile(string fp, IOMode mode) {
  return IO<string>([fp, mode]() {
    string s;
    FILE *f = fopen(fp.c_str(), mode.modeChar);
    if (f == nullptr) {
      throw "f is nullptr";
    } else {
      int c;
      while ((c = fgetc(f)) != EOF) {
        s += c;
      }
      fclose(f);
      return s;
    }
  });
}
// Array<Stl> readStl(stringin) { for_each(lines(in), ); }