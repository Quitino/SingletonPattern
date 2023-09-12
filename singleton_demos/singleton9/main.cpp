#include "sing1.h"
#include "sing2.h"

void fun();
int main(int argc, char **argv) {
//   std::cout << "from main: " << singleton1.val << '\n';
//   std::cout << "from main: " << singleton2.val << '\n';
//   fun();

  size_t res = 0;
  for (unsigned i = 0; i < 999999999; ++i) {
    res += singleton1.val + i; // 防止优化
  }
  return res;
}

// Sing1 construct
// Sing2 construct
// from main: 100
// from main: 101
// from fun: 101
// from fun: 100
// Sing2 destroy
// Sing1 destroy

/*
##  9.第九品（可用）：
• 基本思路
    • 对单例类的功能逻辑与单例逻辑进行划分，分别放入不同的部分
    • 使用CRTP模拟“基类-派生类”行为
• 优点
    • 更容易支持不同的单例实例
    • 使用模板不会引入运行期成本
• 缺点
    • 暂无
*/