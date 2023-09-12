#include "sing.h"
static Sing::Init init;

auto singletonInst2 = singletonInst->val;

int main(int argc, char **argv) {
  Sing::Init init;

  std::cout << "get value: " << singletonInst2 << '\n';
  std::cout << singletonInst << std::endl;
  std::cout << singletonInst->val << std::endl;
}


// Sing construct
// get value: 100
// 0x55da438eeeb0
// 100
// Sing destroy