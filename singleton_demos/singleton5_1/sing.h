#pragma once
#include <iostream>
#include <memory>

class Sing {
 public:
  struct Init {
    Init();
    Init(const Init&) = delete;
    Init& operator=(const Init&) = delete;
  };

 public:
  ~Sing() { std::cout << "Sing destroy\n"; }

 private:
  Sing() {
    std::cout << "Sing construct\n";
    val = 100;
  }

  Sing(const Sing&) = delete;
  Sing& operator=(const Sing&) = delete;

 public:
  int val;
};

template <typename T>
class MyUniquePtr : public std::unique_ptr<T> {
 public:
// consteval 
// constexpr 不能使用 constexpr 会被指定为常量无法再进行更改
  MyUniquePtr() : std::unique_ptr<T>() {}
};

extern MyUniquePtr<Sing> singletonInst;