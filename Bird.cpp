#include "Bird.h"
#include <cstring>

void Bird::copyStrings(const char* b, const char* c, const char* d, const char* h) {
    breed = new char[strlen(b) + 1]; strcpy(breed, b);
    color = new char[strlen(c) + 1]; strcpy(color, c);
    diet = new char[strlen(d) + 1]; strcpy(diet, d);
    habitat = new char[strlen(h) + 1]; strcpy(habitat, h);
}

void Bird::freeStrings() { delete[] breed; delete[] color; delete[] diet; delete[] habitat; }

Bird::Bird() { copyStrings("Unknown", "Unknown", "Unknown", "Unknown"); }
Bird::Bird(const char* b, const char* c, const char* d, const char* h) { copyStrings(b, c, d, h); }
Bird::Bird(const Bird& other) : Base(other) { copyStrings(other.breed, other.color, other.diet, other.habitat); }
Bird::~Bird() { freeStrings(); }

const char* Bird::getBreed() const { return breed; }
void Bird::setBreed(const char* b) { delete[] breed; breed = new char[strlen(b) + 1]; strcpy(breed, b); }
const char* Bird::getColor() const { return color; }
void Bird::setColor(const char* c) { delete[] color; color = new char[strlen(c) + 1]; strcpy(color, c); }
const char* Bird::getDiet() const { return diet; }
void Bird::setDiet(const char* d) { delete[] diet; diet = new char[strlen(d) + 1]; strcpy(diet, d); }
const char* Bird::getHabitat() const { return habitat; }
void Bird::setHabitat(const char* h) { delete[] habitat; habitat = new char[strlen(h) + 1]; strcpy(habitat, h); }

void Bird::display() const {
    std::cout << "--- ПТИЦА ---\nПорода: " << breed << "\nОкрас: " << color << "\nДиета: " << diet << "\nАреал: " << habitat << std::endl;
}

void Bird::inputFromKeyboard() {
    char buf[256];
    std::cout << "Введите породу птицы: "; std::cin.getline(buf, sizeof(buf)); if(!strlen(buf)) throw std::invalid_argument("Пусто!"); setBreed(buf);
    std::cout << "Введите окрас птицы: "; std::cin.getline(buf, sizeof(buf)); if(!strlen(buf)) throw std::invalid_argument("Пусто!"); setColor(buf);
    std::cout << "Введите диету: "; std::cin.getline(buf, sizeof(buf)); if(!strlen(buf)) throw std::invalid_argument("Пусто!"); setDiet(buf);
    std::cout << "Введите ареал: "; std::cin.getline(buf, sizeof(buf)); if(!strlen(buf)) throw std::invalid_argument("Пусто!"); setHabitat(buf);
}

void Bird::saveToFile(std::ofstream& out) const {
    out << "Bird\n" << breed << "\n" << color << "\n" << diet << "\n" << habitat << "\n";
}

void Bird::loadFromFile(std::ifstream& in) {
    char buf[256];
    in.getline(buf, sizeof(buf)); setBreed(buf);
    in.getline(buf, sizeof(buf)); setColor(buf);
    in.getline(buf, sizeof(buf)); setDiet(buf);
    in.getline(buf, sizeof(buf)); setHabitat(buf);
}

Bird& Bird::operator=(const Bird& other) {
    if (this != &other) { freeStrings(); copyStrings(other.breed, other.color, other.diet, other.habitat); }
    return *this;
}