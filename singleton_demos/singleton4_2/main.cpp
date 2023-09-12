#include "sing.h"
// 和singleton_4的区别就是这一行
// 按推理，singletonInst2应该是int对象
// 模拟的是另外一个单例需要使用之前的单例进行初始化，这时就存在static
// initialization order fiasco 问题
auto singletonInst2 = singletonInst;

int main(int argc, char **argv) {
  std::cout << "singletonInst: " << singletonInst << '\n';
  std::cout << "singletonInst2: " << singletonInst2 << '\n';
}

// g++ -c ./main.cpp
// g++ -c ./sing.cpp
// g++ ./main.o ./sing.o -o ./ms
// g++ ./sing.o ./main.o -o ./sm

// ./ms
// Sing construct
// singletonInst: 0x55ec5afbe174
// singletonInst2: 0 // 非法地址
// Sing destroy


// 这个顺序得到合法的地址：
// ./sm
// Sing construct
// singletonInst: 0x55e1623af164
// singletonInst2: 0x55e1623af164
// Sing destroy

/*
ms 和 sm 有什么区别呢？唯一的区别就是链接文件顺序有变化，为什么呢？

C++对全局对象的初始化顺序规定不是很严格，对于两个翻译单元（string、main）中的全局对象，谁先谁后的问题，没有严格定义；
此时就可能是singletonInst2先初始化，导致段错误。
*/