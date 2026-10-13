#include "Fish.h"
#include <cstring>

void Fish::copyStrings(const char* b, const char* c, const char* f) {
    breed = new char[strlen(b) + 1];
    strcpy(breed, b);
    color = new char[strlen(c) + 1];
    strcpy(color, c);
    feedType = new char[strlen(f) + 1];
    strcpy(feedType, f);
}

void Fish::freeStrings() {
    delete[] breed;
    delete[] color;
    delete[] feedType;
}

Fish::Fish() { copyStrings("Unknown", "Unknown", "Unknown"); }

Fish::Fish(const char* b, const char* c, const char* f) { copyStrings(b, c, f); }

Fish::Fish(const Fish& other) : Base(other) { copyStrings(other.breed, other.color, other.feedType); }

Fish::~Fish() { freeStrings(); }

const char* Fish::getBreed() const { return breed; }
void Fish::setBreed(const char* b) {
    delete[] breed;
    breed = new char[strlen(b) + 1];
    strcpy(breed, b);
}

const char* Fish::getColor() const { return color; }
void Fish::setColor(const char* c) {
    delete[] color;
    color = new char[strlen(c) + 1];
    strcpy(color, c);
}

const char* Fish::getFeedType() const { return feedType; }
void Fish::setFeedType(const char* f) {
    delete[] feedType;
    feedType = new char[strlen(f) + 1];
    strcpy(feedType, f);
}

void Fish::display() const {
    std::cout << "--- РЫБА ---\nПорода: " << breed << "\nОкрас: " << color << "\nТип питания: " << feedType << std::endl;
}

void Fish::inputFromKeyboard() {
    char buf[256];
    std::cout << "Введите породу рыбы: ";
    std::cin.getline(buf, sizeof(buf));
    if (strlen(buf) == 0) throw std::invalid_argument("Поле не может быть пустым!");
    setBreed(buf);

    std::cout << "Введите окрас рыбы: ";
    std::cin.getline(buf, sizeof(buf));
    if (strlen(buf) == 0) throw std::invalid_argument("Поле не может быть пустым!");
    setColor(buf);

    std::cout << "Введите тип питания: ";
    std::cin.getline(buf, sizeof(buf));
    if (strlen(buf) == 0) throw std::invalid_argument("Поле не может быть пустым!");
    setFeedType(buf);
}

void Fish::saveToFile(std::ofstream& out) const {
    out << "Fish\n" << breed << "\n" << color << "\n" << feedType << "\n";
}

void Fish::loadFromFile(std::ifstream& in) {
    char buf[256];
    in.getline(buf, sizeof(buf)); setBreed(buf);
    in.getline(buf, sizeof(buf)); setColor(buf);
    in.getline(buf, sizeof(buf)); setFeedType(buf);
}

Fish& Fish::operator=(const Fish& other) {
    if (this != &other) {
        freeStrings();
        copyStrings(other.breed, other.color, other.feedType);
    }
    return *this;
}