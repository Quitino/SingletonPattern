#pragma once
#include <iostream>

class Sing {
 public:
  Sing() {
    std::cout << "Sing construct\n";
    val = 100;
  }
  ~Sing() { std::cout << "Sing destroy\n"; }

  int val;  // 表示单例里面包含的内容，实际项目中有很多内容
};

extern Sing singletonInst;