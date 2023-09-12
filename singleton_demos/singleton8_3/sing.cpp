#include "sing.h"

#include <iostream>
#include <memory>

alignas(Sing) static char singBuf[sizeof(Sing)];

// 目的：对8_2代码进行整理
Sing* Ptr() { return reinterpret_cast<Sing*>(singBuf); }
Sing& singletonInst = *(Ptr());

Sing::Init::Init() {
  auto& count = RefCount();
  auto ori = count.fetch_add(1);
  if (ori == 0) {
    Sing* ptr = Ptr();
    new (ptr) Sing();
  }
}

Sing::Init::~Init() {
  auto& count = RefCount();
  auto ori = count.fetch_sub(1);
  if (ori == 1) {
    Sing* ptr = Ptr();
    ptr->~Sing();
  }
}
