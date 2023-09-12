#pragma once
#include <iostream>

// • 基本思路
//     • 引入全局对象，区分单例的初始化与调用
//     • 静态函数用于初始化；全局对象用于后续调用
class Sing {
 public:
  //  静态函数用于初始化；
  static const Sing* Instance() {
    static Sing inst;
    return &inst;
  }

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
// 全局对象用于后续调用
extern const Sing* singletonInst;