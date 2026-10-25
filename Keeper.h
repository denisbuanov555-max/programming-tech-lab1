#ifndef KEEPER_H
#define KEEPER_H

#include "Base.h"
#include "Fish.h"
#include "Bird.h"
#include "Cat.h"

class Keeper {
private:
  Base** items;       // Сырой массив указателей вместо std::vector
  size_t size;
  size_t capacity;

  void resize(size_t newCapacity);

public:
  Keeper();
  Keeper(const Keeper& other);
  ~Keeper();

  void add(Base* item);
  void remove(size_t index);
  void displayAll() const;
  void edit(size_t index);

  void saveToFile(const char* filename) const;
  void loadFromFile(const char* filename);

  size_t getSize() const { return size; }
  Base* operator[](size_t index);
};

#endif // KEEPER_H