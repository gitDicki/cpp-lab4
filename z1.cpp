#include "Time.h"
#include <iostream>
#include <limits>
#include <string>

int correct_input(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail()) {
            std::cout << "Ошибка ввода. Ожидалось целое число." << std::endl;
            std::cin.clear();
            
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}

int main() {
    int hours;
    int minutes;
    hours = correct_input("Введите количество часов: ");
    minutes = correct_input("Введите количество минут: ");

    Time t(hours, minutes);
    std::cout << "Текущее время: "<< t << std::endl;
    
    minutes = correct_input("Введите количество минут: ");
    t.add_minutes(minutes);
    std::cout << "Время после добвления " << minutes << " минут: "<< t << std::endl;
}