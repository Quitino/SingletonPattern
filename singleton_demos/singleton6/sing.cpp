#include "sing.h"

#include <iostream>
#include <memory>

// 只对当前翻译单元可见
// unsigned 是内建数据类型，他的初始化时平凡缺省初始化，0初始化+缺省初始化，固定的
static unsigned singletonCount;
Sing* singletonInst;

// • 基本思路2——运行期平凡缺省初始化；
//     • 使用基本数据类型代替抽象数据类型作为全局对象
//     • 通过引用计数控制销毁时机
Sing::Init::Init() {
  ++singletonCount;  // 缺点：多线程不安全
  if (singletonCount == 1) {
    singletonInst = new Sing();
  }
}

Sing::Init::~Init() {
  --singletonCount;
  if (singletonCount == 0) {
    delete singletonInst;
    singletonInst = nullptr;
  }
}