#include "sing.h"

#include <iostream>
#include <memory>


// constinit
// 定义
// unique_ptr的析构函数需要定义sing的析构函数，所以要求sing的析构函数是public的
std::unique_ptr<Sing> singletonInst;

// 引入初始化类
Sing::Init::Init() {
  if (!singletonInst) {
    singletonInst.reset(new Sing());
  }
}
