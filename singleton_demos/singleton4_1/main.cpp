#include "sing.h"
// 和singleton_4的区别就是这一行
// 按推理，singletonInst2应该是int对象
// 模拟的是另外一个单例需要使用之前的单例进行初始化，这时就存在static initialization order fiasco 问题
auto singletonInst2 = singletonInst.val;

int main(int argc, char **argv) {
  std::cout << "get value: " << singletonInst2 << '\n';
}


// g++ -c ./main.cpp
// g++ -c ./sing.cpp
// g++ ./main.o ./sing.o -o ./ms
// g++ ./sing.o ./main.o -o ./sm

// ./ms
// Segmentation fault (core dumped)

// ./sm
// Sing construct
// get value: 100
// Sing destroy

/*
ms 和 sm 有什么区别呢？唯一的区别就是链接文件顺序有变化，为什么呢？

C++对全局对象的初始化顺序规定不是很严格，对于两个翻译单元（string、main）中的全局对象，谁先谁后的问题，没有严格定义；
此时就可能是singletonInst2先初始化，导致段错误。
*/