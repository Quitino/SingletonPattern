#pragma once
#include <atomic>
#include <iostream>

class Sing {
 public:
  struct Init {
    Init();
    Init(const Init&) = delete;
    Init& operator=(const Init&) = delete;
    ~Init();

    // 使用原子操作，保证线程安全
    static std::atomic<unsigned>& RefCount() {
      // 定义为静态类型
      static std::atomic<unsigned> singletonCount{0};
      return singletonCount;
    }
  };

 private:
  Sing() {
    std::cout << "Sing construct\n";
    val = 100;
  }

  ~Sing() { std::cout << "Sing destroy\n"; }

  Sing(const Sing&) = delete;
  Sing& operator=(const Sing&) = delete;

 public:
  int val;
};

extern Sing* singletonInst;