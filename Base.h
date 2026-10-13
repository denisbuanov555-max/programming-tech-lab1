#ifndef BASE_H
#define BASE_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <stdexcept>

class Base {
public:
  Base();
  Base(const Base& other);
  virtual ~Base();

  virtual void display() const = 0;
  virtual void inputFromKeyboard() = 0;
  virtual void saveToFile(std::ofstream& out) const = 0;
  virtual void loadFromFile(std::ifstream& in) = 0;
  virtual const char* getType() const = 0; // Изменили std::string на const char*
};

#endif // BASE_H