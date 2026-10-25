#include "Cat.h"
#include <cstring>

void Cat::copyStrings(const char* b, const char* c, const char* o, const char* n) {
    breed = new char[strlen(b) + 1]; strcpy(breed, b);
    color = new char[strlen(c) + 1]; strcpy(color, c);
    ownerName = new char[strlen(o) + 1]; strcpy(ownerName, o);
    nickname = new char[strlen(n) + 1]; strcpy(nickname, n);
}

void Cat::freeStrings() { delete[] breed; delete[] color; delete[] ownerName; delete[] nickname; }

Cat::Cat() { copyStrings("Unknown", "Unknown", "Unknown", "Unknown"); }
Cat::Cat(const char* b, const char* c, const char* o, const char* n) { copyStrings(b, c, o, n); }
Cat::Cat(const Cat& other) : Base(other) { copyStrings(other.breed, other.color, other.ownerName, other.nickname); }
Cat::~Cat() { freeStrings(); }

const char* Cat::getBreed() const { return breed; }
void Cat::setBreed(const char* b) { delete[] breed; breed = new char[strlen(b) + 1]; strcpy(breed, b); }
const char* Cat::getColor() const { return color; }
void Cat::setColor(const char* c) { delete[] color; color = new char[strlen(c) + 1]; strcpy(color, c); }
const char* Cat::getOwnerName() const { return ownerName; }
void Cat::setOwnerName(const char* o) { delete[] ownerName; ownerName = new char[strlen(o) + 1]; strcpy(ownerName, o); }
const char* Cat::getNickname() const { return nickname; }
void Cat::setNickname(const char* n) { delete[] nickname; nickname = new char[strlen(n) + 1]; strcpy(nickname, n); }

void Cat::display() const {
    std::cout << "--- КОШКА ---\nКличка: " << nickname << "\nПорода: " << breed << "\nОкрас: " << color << "\nВладелец: " << ownerName << std::endl;
}

void Cat::inputFromKeyboard() {
    char buf[256];
    std::cout << "Введите кличку: "; std::cin.getline(buf, sizeof(buf)); if(!strlen(buf)) throw std::invalid_argument("Пусто!"); setNickname(buf);
    std::cout << "Введите породу: "; std::cin.getline(buf, sizeof(buf)); if(!strlen(buf)) throw std::invalid_argument("Пусто!"); setBreed(buf);
    std::cout << "Введите окрас: "; std::cin.getline(buf, sizeof(buf)); if(!strlen(buf)) throw std::invalid_argument("Пусто!"); setColor(buf);
    std::cout << "Введите владельца: "; std::cin.getline(buf, sizeof(buf)); if(!strlen(buf)) throw std::invalid_argument("Пусто!"); setOwnerName(buf);
}

void Cat::saveToFile(std::ofstream& out) const {
    out << "Cat\n" << breed << "\n" << color << "\n" << ownerName << "\n" << nickname << "\n";
}

void Cat::loadFromFile(std::ifstream& in) {
    char buf[256];
    in.getline(buf, sizeof(buf)); setBreed(buf);
    in.getline(buf, sizeof(buf)); setColor(buf);
    in.getline(buf, sizeof(buf)); setOwnerName(buf);
    in.getline(buf, sizeof(buf)); setNickname(buf);
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) { freeStrings(); copyStrings(other.breed, other.color, other.ownerName, other.nickname); }
    return *this;
}