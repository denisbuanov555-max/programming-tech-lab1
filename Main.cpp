#include <iostream>
#include <limits>
#include <windows.h>
#include "Keeper.h"

void printMenu() {
    std::cout << "\n================ МЕНЮ УПРАВЛЕНИЯ ===============-\n"
              << "1. Добавить Рыбу\n"
              << "2. Добавить Птицу\n"
              << "3. Добавить Кошку\n"
              << "4. Вывести все записи\n"
              << "5. Редактировать запись\n"
              << "6. Удалить запись\n"
              << "7. Сохранить в файл\n"
              << "8. Загрузить из файла\n"
              << "0. Выход\n"
              << "Выберите пункт: ";
}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    Keeper keeper;
    int choice = -1;

    while (choice != 0) {
        printMenu();
        if (!(std::cin >> choice)) {
            std::cout << "Ошибка ввода! Введите число.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choice = -1; // ВАЖНО: сбрасываем в -1, чтобы цикл не думал, что это был выбор "0. Выход"
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        try {
            switch (choice) {
                case 1: {
                    Base* f = new Fish();
                    f->inputFromKeyboard();
                    keeper.add(f);
                    break;
                }
                case 2: {
                    Base* b = new Bird();
                    b->inputFromKeyboard();
                    keeper.add(b);
                    break;
                }
                case 3: {
                    Base* c = new Cat();
                    c->inputFromKeyboard();
                    keeper.add(c);
                    break;
                }
                case 4:
                    keeper.displayAll();
                    break;
                case 5: {
                    keeper.displayAll();
                    if (keeper.getSize() == 0) break;
                    std::cout << "Введите номер записи для редактирования: ";
                    size_t idx;
                    std::cin >> idx;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    keeper.edit(idx - 1);
                    break;
                }
                case 6: {
                    keeper.displayAll();
                    if (keeper.getSize() == 0) break;
                    std::cout << "Введите номер записи для удаления: ";
                    size_t idx;
                    std::cin >> idx;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    keeper.remove(idx - 1);
                    break;
                }
                case 7: {
                    char filename[256];
                    std::cout << "Введите имя файла для сохранения (например, base_test.txt): ";
                    std::cin.getline(filename, sizeof(filename));
                    keeper.saveToFile(filename);
                    break;
                }
                case 8: {
                    char filename[256];
                    std::cout << "Введите имя файла для загрузки: ";
                    std::cin.getline(filename, sizeof(filename));
                    keeper.loadFromFile(filename);
                    break;
                }
                case 0:
                    std::cout << "Выход из программы.\n";
                    break;
                default:
                    std::cout << "Неверный пункт меню! Попробуйте снова.\n";
                    break;
            }
        } catch (const std::exception& e) {
            std::cerr << "ИСКЛЮЧЕНИЕ: " << e.what() << std::endl;
        }
    }

    return 0;
}