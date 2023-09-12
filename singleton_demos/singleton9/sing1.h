#pragma once
#include <iostream>

#include "sing_temp.h"

// todo: 派生自SingTemp,看上去有点像循环定义,实际上是一个典型的CRPT
class Sing1 : public SingTemp<Sing1> {
  friend SingTemp<Sing1>;

 private:
  Sing1() : SingTemp<Sing1>() {
    std::cout << "Sing1 construct\n";
    val = 100;
  }

  ~Sing1() { std::cout << "Sing1 destroy\n"; }

 public:
  int val;
};

static Sing1::Init sing1Init;
static Sing1& singleton1 = *Sing1::Ptr();