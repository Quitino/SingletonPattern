#pragma once
#include <iostream>

class Sing {
 public:
  static const Sing& Instance() {
    // 缺点：由于多线程安全所引入的额外成本,都要求对类进行加锁以保证线程安全
    // 不管是读还是写，都需要先加锁判断是否已经存在实现
    // 实际上，读操作可以不加锁就是安全的
    static Sing inst;
    return inst;
  }

 private:
  Sing() {
    std::cout << "Sing construct\n";
    val = 100;
  }

  ~Sing() { std::cout << "Sing destroy\n"; }
  // 对于第二品的改进，限制拷贝（移动）构造，拷贝（移动）赋值进一步杜绝非法复制
  // 如果声明了拷贝构造函数，而没有声明移动构造函数时；当我们要涉及移动构造时，系统会尝试调用拷贝构造，因此这里只限制拷贝构造也就相当于限制了移动构造
  Sing(const Sing&) = delete;
  Sing& operator=(const Sing&) = delete;

 public:
  int val;
};
