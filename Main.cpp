#include <iostream>
#include <windows.h> // Обязательно для SetConsoleOutputCP / SetConsoleCP
#include "Fish.h"
#include "Bird.h"

int main() {
    // Установка кодировки UTF-8 для консоли Windows
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    std::cout << "--- Этап 2: Проверка классов Рыба и Птица ---" << std::endl;

    Fish fish("Карп", "Зеркальный", "Растительный");
    fish.display();

    std::cout << std::endl;

    Bird bird("Орел", "Бурый", "Мясо", "Горы");
    bird.display();

    return 0;
}