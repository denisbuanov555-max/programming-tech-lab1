#ifndef BIRD_H
#define BIRD_H

#include "Base.h"

class Bird : public Base {
private:
  char* breed;
  char* color;
  char* diet;
  char* habitat;

  void copyStrings(const char* b, const char* c, const char* d, const char* h);
  void freeStrings();

public:
  Bird();
  Bird(const char* b, const char* c, const char* d, const char* h);
  Bird(const Bird& other);
  ~Bird() override;

  const char* getBreed() const; void setBreed(const char* b);
  const char* getColor() const; void setColor(const char* c);
  const char* getDiet() const; void setDiet(const char* d);
  const char* getHabitat() const; void setHabitat(const char* h);

  void display() const override;
  void inputFromKeyboard() override;
  void saveToFile(std::ofstream& out) const override;
  void loadFromFile(std::ifstream& in) override;
  const char* getType() const override { return "Bird"; }

  Bird& operator=(const Bird& other);
};

#endif // BIRD_H