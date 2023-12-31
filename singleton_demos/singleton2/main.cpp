#include "sing.h"

int main(int argc, char **argv) {
  std::cout << "get value: " << Sing::Instance().val << '\n';

  // 缺点： 没有完全阻止用户构造该类的多个对象
  // new sing 执行构造函数，构造函数传入一个对象的引用,相当于调用了一个拷贝构造函数
  // Sing类里面只定义了普通构造函数，没有定义拷贝构造函数,此时编译器会为类合成一个拷贝构造函数且为public的
  Sing *sing2 = new Sing(Sing::Instance()); 
  // 在堆上构造，通常是显示销毁，如果不指定就不会销毁，因此不会调用析构函数，是合法可编译的


// Sing(Sing::Instance());
// 这样构造一个临时对象是不行的，分配在栈上，生命周期结束时需要调用析构函数进行销毁，但是析构函数是私有的，无法调用，因此编译出错
}

// get value: Sing construct
// 100
// Sing destroy

/*
##  2.第二品：
• 基本思路
    • 将构造、析构函数设置为私有成员
    • 使用静态成员函数获取唯一的实例
• 优点
    • 可以防止用户不小心构造新的实例
    • （C++11 开始）系统会保证函数内部的静态成员初始化是多线程安全的
• 特点
    • 缓式初始化（lazy initialization）
• 缺点
    • 没有完全阻止用户构造该类的多个对象
*/