#ifndef FISH_H
#define FISH_H

#include "Base.h"


class Fish : public Base {
private:
  char* breed;
  char* color;
  char* feedType;

  void copyStrings(const char* b, const char* c, const char* f);
  void freeStrings();

public:
  Fish();
  Fish(const char* b, const char* c, const char* f);
  Fish(const Fish& other);
  ~Fish() override;

  const char* getBreed() const; void setBreed(const char* b);
  const char* getColor() const; void setColor(const char* c);
  const char* getFeedType() const; void setFeedType(const char* f);

  void display() const override;
  void inputFromKeyboard() override;
  void saveToFile(std::ofstream& out) const override;
  void loadFromFile(std::ifstream& in) override;
  const char* getType() const override { return "Fish"; }

  Fish& operator=(const Fish& other);
};

#endif // FISH_H