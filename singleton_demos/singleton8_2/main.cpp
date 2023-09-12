#include "sing.h"
auto singletonInst2 = singletonInst.val;

int main(int argc, char **argv) {
  std::cout << "get value: " << singletonInst2 << '\n';
  std::cout << singletonInst.val << std::endl;
}


// Sing construct
// get value: 100
// 100
// Sing destroy

/*
##  8.第八品（可用）
• 基本思路
    • 使用引用代替指针
    • 方法1：将原始指针封装到类内部，使用函数提供引用接口
    • 方法2：使用 placement new
• 优点
    • 避免指针赋值而产生的问题
• 缺点
    • 代码组织相对复杂，不易扩展
*/