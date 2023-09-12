#include "sing.h"
// 单例构造在 main 函数之前就执行了
int main(int argc, char **argv) {
  std::cout << "get value: " << singletonInst.val << '\n';
  Sing sing2;
}

//  输出：
// Sing construct
// get value: 100
// Sing construct
// Sing destroy
// Sing destroy

/*##  1.第一品
• 基本思路：使用面向对象的方式对要访问的数据进行封装
• 优点：符合基本的面向对象编程方法
    • 使用类对单例中的内容进行封装
    • 使用类的构造函数初始化数据成员，析构函数释放资源
• 缺点
    • 完全没有阻止用户构造该类的多个对象
*/

