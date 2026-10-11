#include "Base.h"

Base::Base() {
  std::cout << "[Base] Вызван конструктор по умолчанию" << std::endl;
}

Base::Base(const Base& other) {
  std::cout << "[Base] Вызван конструктор копирования" << std::endl;
}

Base::~Base() {
  std::cout << "[Base] Вызван деструктор" << std::endl;
}