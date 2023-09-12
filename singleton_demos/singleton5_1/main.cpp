#include "sing.h"

static Sing::Init init;
auto singletonInst2 = singletonInst->val;

// 之前讲的全局变量，同一翻译单元中，先定义就先初始化；再具体的讲
// Type x;
// 对于这个定义有两种情况：
// - 定义的对象能够在编译期进行求值，同时编译期决定要对当前对象进行求值，此时系统就会在编译期间进行求值，期间相关的计算结果会保留到编译完的可执行程序中，加载可执行程序的时候会直接将数值加载到内存里，然后将这块内存与变量相关联 ==> 常量初始化
// - 定义的对象能够在编译期进行求值，但编译期拒绝对当前对象进行求值，或该对象本身不能在编译期进行求值；此时系统就会将该数据类型占据内存大小的信息保留到可执行程序中，加载可执行程序的时候会根据该信息进行内存开辟，同时将内存中的数值全部置为0； ==> 0初始化； 0初始化后再进行计算初始化

int main(int argc, char **argv) {
  std::cout << "get value: " << singletonInst2 << '\n';
  std::cout << singletonInst.get() << std::endl;
  std::cout << singletonInst->val << std::endl;
}

// 和singleton5框架上的区别在于将UniquePtr使用MyUniquePtr包装了一层

// • 缺点
//     • 似乎可以解决 static initialization order fiasco
//     问题，但实际上程序包含了更深层次的隐患：可能出现未定义的行为。

// g++ -c ./main.cpp #-std=c++20
// g++ -c ./sing.cpp #-std=c++20
// g++ ./main.o ./sing.o -o ./ms
// g++ ./sing.o ./main.o -o ./sm

// ./sm
// Sing construct
// get value: 100
// 0x5556970e0eb0
// 100
// Sing destroy

// ./ms
// Sing construct
// get value: 100
// 0
// Segmentation fault (core dumped)



// main  sing 链接顺序时：
// - main.cpp中 全局变量 static Sing::Init init; （对 singletonInst 进行赋值）auto singletonInst2 = singletonInst->val;【这里还涉及到一个先调用后构造的未定义行为，在main函数先翻译时，singletonInst是为定义的】
// - sing.cpp中 全局变量 MyUniquePtr<Sing> singletonInst; // MyUniquePtr 的构造函数执行的是 0 初始化 + 缺省初始化； singletonInst 为 “0”，因此出现段错误


// sing main 连接顺序时：
// - sing.cpp中 全局变量 MyUniquePtr<Sing> singletonInst; // MyUniquePtr 的构造函数执行的是 0 初始化 + 缺省初始化； singletonInst 为 “0”
// - main.cpp中 全局变量 static Sing::Init init; （对 singletonInst 进行赋值）auto singletonInst2 = singletonInst->val;

// 纠错办法为，将 MyUniquePtr 的构造函数改为编译期执行，即加上关键字 `consteval` 或 `constexpr`

// ./ms
// Sing construct
// get value: 100
// 0x55f693d19eb0
// 100
// Sing destroy
