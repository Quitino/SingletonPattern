#include "sing.h"

#include <iostream>
#include <memory>

// 之前讲的全局变量，同一翻译单元中，先定义就先初始化；再具体的讲
// Type x;
// 对于这个定义有两种情况：
// - 定义的对象能够在编译期进行求值，同时编译期决定要对当前对象进行求值，此时系统就会在编译期间进行求值，期间相关的计算结果会保留到编译完的可执行程序中，加载可执行程序的时候会直接将数值加载到内存里，然后将这块内存与变量相关联 ==> 常量初始化
// - 定义的对象能够在编译期进行求值，但编译期拒绝对当前对象进行求值，或该对象本身不能在编译期进行求值；此时系统就会将该数据类型占据内存大小的信息保留到可执行程序中，加载可执行程序的时候会根据该信息进行内存开辟，同时将内存中的数值全部置为0； ==> 0初始化； 0初始化后再进行计算初始化

MyUniquePtr<Sing> singletonInst;
// MyUniquePtr 的构造函数执行的是 0 初始化 + 缺省初始化；

// constinit MyUniquePtr<Sing> singletonInst;

Sing::Init::Init() {
  if (!singletonInst) {
    singletonInst.reset(new Sing());
  }
}

// static Sing::Init init;