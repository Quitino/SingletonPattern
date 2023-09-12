#include "sing.h"

#include <iostream>
#include <memory>

// 分配一块内存
alignas(Sing) char singBuf[sizeof(Sing)];

Sing::Init::Init() {
  auto& count = RefCount();
  auto ori = count.fetch_add(1);
  if (ori == 0) {
    // 将singBuf转换为sing的指针
    // • 基本思路
    // • 使用引用代替指针
    // • 方法2：使用 placement new
    Sing* ptr = reinterpret_cast<Sing*>(singBuf);
    new (ptr) Sing();
  }
}

Sing::Init::~Init() {
  auto& count = RefCount();
  auto ori = count.fetch_sub(1);
  if (ori == 1) {
    Sing* ptr = reinterpret_cast<Sing*>(singBuf);
    ptr->~Sing();
  }
}
