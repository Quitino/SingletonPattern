#include "sing.h"

#include <iostream>
#include <memory>

// • 缺点
//     • 指针有被修改的风险
Sing* singletonInst;

// 可能存在风险，两个程序同时首次调用这个函数；
// 一个客户端调用到`auto ori = count.fetch_add(1); `后就挂起了，
// 另一个客户端到这里检测 ori != 0,就没构造，但实际上前面也没构造，就会出错

// 但从本例的使用【在main函数之前全局域内进行实例化】，不会涉及到多线程，问题不大
Sing::Init::Init() {
  auto& count = Sing::Init::RefCount();
  auto ori = count.fetch_add(1); // 保证线程安全
  if (ori == 0) {
    singletonInst = new Sing();
  }
}

Sing::Init::~Init() {
  auto& count = Sing::Init::RefCount();
  auto ori = count.fetch_sub(1);
  if (ori == 1) {
    delete singletonInst;
    singletonInst = nullptr;
  }
}