#include "sing.h"

int main(int argc, char** argv) {
//   std::cout << "get value: " << Sing::Instance().val << '\n';
  // 无法通过编译
  // Sing* s = new Sing(std::move(Sing::Instance()));

  size_t res = 0;
  for (unsigned i = 0; i < 999999999; ++i)
  {
      res += Sing::Instance().val + i;
  }
  return res;
}


// get value: Sing construct
// 100
// Sing destroy

/*
##  3.第三品（常见实现，可用）：
• 基本思路
    • 通过限制拷贝（移动）构造，拷贝（移动）赋值进一步杜绝非法复制
• 优点
    • 杜绝构造新的实例
• 缺点
    • 由于多线程安全所引入的额外成本
*/