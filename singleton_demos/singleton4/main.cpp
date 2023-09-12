#include "sing.h"

// 单例对象在main函数之前进行实例化
int main(int argc, char **argv) {
  std::cout << "get value: " << singletonInst.val << '\n';
}


// Sing construct
// get value: 100
// Sing destroy

/*
##  4.第四品：
• 基本思路
    • 引入全局对象，区分单例的初始化与调用
    • 静态函数用于初始化；全局对象用于后续调用
• 优点
    • 减少了调用所付出的成本
• 特点
    • 热初始化（eager initialization）
• 缺点
    • static initialization order fiasco[失败] 问题，程序存在较大隐患
*/