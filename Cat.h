#ifndef CAT_H
#define CAT_H

#include "Base.h"

class Cat : public Base {
private:
  char* breed;
  char* color;
  char* ownerName;
  char* nickname;

  void copyStrings(const char* b, const char* c, const char* o, const char* n);
  void freeStrings();

public:
  Cat();
  Cat(const char* b, const char* c, const char* o, const char* n);
  Cat(const Cat& other);
  ~Cat() override;

  const char* getBreed() const; void setBreed(const char* b);
  const char* getColor() const; void setColor(const char* c);
  const char* getOwnerName() const; void setOwnerName(const char* o);
  const char* getNickname() const; void setNickname(const char* n);

  void display() const override;
  void inputFromKeyboard() override;
  void saveToFile(std::ofstream& out) const override;
  void loadFromFile(std::ifstream& in) override;
  const char* getType() const override { return "Cat"; }

  Cat& operator=(const Cat& other);
};

#endif // CAT_H