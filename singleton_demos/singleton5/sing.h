#pragma once
#include <iostream>
#include <memory>

// • 基本思路
//     • 引入初始化类
//     • 初始化类是单例类的子类，可以访问单例类的所有成员
//     • 通过初始化类的实例作为纽带，一定程度上控制初始化顺序
class Sing {
 public:
  // 引入初始化类
  struct Init {
    Init();
    Init(const Init&) = delete;
    Init& operator=(const Init&) = delete;
  };

 public:
  //  析构函数声明为public
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

// 声明
extern std::unique_ptr<Sing> singletonInst;