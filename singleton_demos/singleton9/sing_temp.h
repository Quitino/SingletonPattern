#pragma once
#include <atomic>

// 模板类，接受一个模板参数，模板参数就是最终需要实现的单例类
template <typename T>
class SingTemp {
 public:
  struct Init {
    Init() {
      auto& count = RefCount();
      auto ori = count.fetch_add(1);
      if (ori == 0) {
        T* ptr = SingTemp::Ptr();
        new (ptr) T();
      }
    }

    ~Init() {
      auto& count = RefCount();
      auto ori = count.fetch_sub(1);
      if (ori == 1) {
        T* ptr = SingTemp::Ptr();
        ptr->~T();
      }
    }

    static auto& RefCount() {
      static std::atomic<unsigned> count{0};
      return count;
    }

    Init(const Init&) = delete;
    Init& operator=(const Init&) = delete;
  };

  // 注意这里是protected，便于后面的继承
 protected:
  SingTemp() = default;
  ~SingTemp() = default;
  SingTemp(const SingTemp&) = delete;
  SingTemp& operator=(const SingTemp&) = delete;

 public:
  static T* Ptr() {
    // 静态数组,用于placement new
    alignas(T) static char singBuf[sizeof(T)];
    // 将数组转换为指针
    return reinterpret_cast<T*>(singBuf);
  }
};
