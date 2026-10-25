#include "Keeper.h"
#include <cstring>
#include <iostream>

Keeper::Keeper() : items(nullptr), size(0), capacity(0) {
    std::cout << "[Keeper] Вызван конструктор по умолчанию\n";
}

Keeper::Keeper(const Keeper& other) : size(other.size), capacity(other.capacity) {
    std::cout << "[Keeper] Вызван конструктор копирования\n";
    if (capacity > 0) {
        items = new Base*[capacity];
        for (size_t i = 0; i < size; ++i) {
            const char* type = other.items[i]->getType();
            if (strcmp(type, "Fish") == 0) items[i] = new Fish(*dynamic_cast<Fish*>(other.items[i]));
            else if (strcmp(type, "Bird") == 0) items[i] = new Bird(*dynamic_cast<Bird*>(other.items[i]));
            else if (strcmp(type, "Cat") == 0) items[i] = new Cat(*dynamic_cast<Cat*>(other.items[i]));
        }
    } else { items = nullptr; }
}

Keeper::~Keeper() {
    std::cout << "[Keeper] Вызван деструктор\n";
    for (size_t i = 0; i < size; ++i) delete items[i];
    delete[] items;
}

void Keeper::resize(size_t newCapacity) {
    Base** newItems = new Base*[newCapacity];
    for (size_t i = 0; i < size; ++i) newItems[i] = items[i];
    delete[] items;
    items = newItems;
    capacity = newCapacity;
}

void Keeper::add(Base* item) {
    if (size >= capacity) resize(capacity == 0 ? 2 : capacity * 2);
    items[size++] = item;
    std::cout << "Элемент успешно добавлен!\n";
}

void Keeper::remove(size_t index) {
    if (index >= size) throw std::out_of_range("Индекс вне диапазона!");
    delete items[index];
    for (size_t i = index; i < size - 1; ++i) items[i] = items[i + 1];
    size--;
    std::cout << "Элемент удален.\n";
}

void Keeper::displayAll() const {
    if (size == 0) { std::cout << "Контейнер пуст.\n"; return; }
    for (size_t i = 0; i < size; ++i) {
        std::cout << "\n[Запись №" << i + 1 << "]\n";
        items[i]->display();
    }
}

void Keeper::edit(size_t index) {
    if (index >= size) throw std::out_of_range("Некорректный индекс!");
    std::cout << "Редактирование записи №" << index + 1 << ":\n";
    items[index]->inputFromKeyboard();
}

void Keeper::saveToFile(const char* filename) const {
    std::ofstream out(filename);
    if (!out.is_open()) throw std::runtime_error("Ошибка открытия файла для записи!");
    out << size << "\n";
    for (size_t i = 0; i < size; ++i) items[i]->saveToFile(out);
    out.close();
    std::cout << "Данные сохранены в файл.\n";
}

void Keeper::loadFromFile(const char* filename) {
    std::ifstream in(filename);
    if (!in.is_open()) throw std::runtime_error("Ошибка открытия файла для чтения!");
    for (size_t i = 0; i < size; ++i) delete items[i];
    delete[] items;
    items = nullptr;
    size = 0;
    capacity = 0;

    size_t count;
    if (!(in >> count)) return;

    char ignore[256];
    in.getline(ignore, sizeof(ignore));

    for (size_t i = 0; i < count; ++i) {
        char type[256];
        while (in.peek() == '\n' || in.peek() == '\r') in.get();
        in.getline(type, sizeof(type));
        size_t len = strlen(type);
        if (len > 0 && type[len - 1] == '\r') type[len - 1] = '\0';

        Base* newItem = nullptr;
        if (strcmp(type, "Fish") == 0) newItem = new Fish();
        else if (strcmp(type, "Bird") == 0) newItem = new Bird();
        else if (strcmp(type, "Cat") == 0) newItem = new Cat();

        if (newItem) {
            newItem->loadFromFile(in);
            add(newItem);
        }
    }
    in.close();
    std::cout << "Данные успешно загружены из файла.\n";
}

Base* Keeper::operator[](size_t index) {
    if (index >= size) throw std::out_of_range("Индекс вне границ!");
    return items[index];
}