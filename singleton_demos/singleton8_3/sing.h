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
    static auto& RefCount() {
      static std::atomic<unsigned> count{0};
      return count;
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

static Sing::Init init;
extern Sing& singletonInst;