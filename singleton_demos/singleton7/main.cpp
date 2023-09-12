#include "sing.h"
static Sing::Init init;
auto singletonInst2 = singletonInst->val;

int main(int argc, char **argv) {
  std::cout << "get value: " << singletonInst2 << '\n';
  std::cout << singletonInst << std::endl;
  // • 缺点
  //     • 指针有被修改的风险
  //   singletonInst = nullptr; // 也是可以编译的，但后面的使用就会报错误了
  std::cout << singletonInst->val << std::endl;
}

// Sing construct
// get value: 100
// 0x564b79514eb0
// 100
// Sing destroy

/*
##  7.第七品
• 基本思路
    • 为引用计数引入线程安全操作
• 优点
    • 全局对象初始化/销毁多线程安全
• 缺点
    • 指针有被修改的风险

*/