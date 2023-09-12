#include "sing.h"
// 定义了一个全局对象
// 通过初始化类的实例作为纽带，一定程度上控制初始化顺序
// 先初始化Init,Init内部会初始化singletonInst
static Sing::Init init;
// 问题：对不不同的翻译单元（cpp文件），每一个文件都需要引入这一句

// 这里进行初始化时就不会出现static initialization order fiasco问题
auto singletonInst2 = singletonInst->val;

int main(int argc, char **argv) {
  std::cout << "get value: " << singletonInst2 << '\n';
}


// Sing construct
// get value: 100
// Sing destroy


// 结果不再依赖链接顺序：
// g++ -c ./main.cpp #-std=c++20
// g++ -c ./sing.cpp #-std=c++20
// g++ ./main.o ./sing.o -o ./ms
// g++ ./sing.o ./main.o -o ./sm

// ./sm
// Sing construct
// get value: 100
// Sing destroy
// ./ms
// Sing construct
// get value: 100
// Sing destroy


// • 缺点
//     • 似乎可以解决 static initialization order fiasco 问题，但实际上程序包含了更深层次的隐患：可能出现未定义的行为。



/*
• 基本思路
    • 引入初始化类
    • 初始化类是单例类的子类，可以访问单例类的所有成员
    • 通过初始化类的实例作为纽带，一定程度上控制初始化顺序
• 优点
    • 初始化类可以精确控制初始化时机
• 缺点
    • 似乎可以解决 static initialization order fiasco 问题，但实际上程序包含了更深层次的隐患：可能出现未定义的行为。
*/