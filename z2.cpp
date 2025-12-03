#include "Time.h"
#include <iostream>
#include <limits>
#include <string>

int correct_input(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail() or value < 0) {
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

    Time t1(hours, minutes);
    std::cout << "Текущее время: "<< t1 << std::endl;

    ++t1;
    std::cout << "После ++: " << t1 << std::endl;

    --t1;
    std::cout << "После--: " << t1 << std::endl;

    minutes = correct_input("Введите количество минут: ");
    t1 = t1 + minutes;
    std::cout << "Время после добвления " << minutes << " минут: "<< t1 << std::endl;

    minutes = correct_input("Введите количество минут: ");
    t1 = t1 - minutes;
    std::cout << "Время после вычитания " << minutes << " минут: "<< t1 << std::endl;

    short int hours2 = static_cast<short int>(t1);
    std::cout << "Только количество часов: " << hours2 << std::endl;

    hours = correct_input("Обнулить значения? (0 или другое число): ");
    if (hours == 0){
        t1.minutes = 0;
        t1.hours = 0;
    }

    if (!static_cast<bool>(t1)){
        std::cout << "Часы и минусы равны 0" << std::endl;
    }
    else {
        std::cout << "Часы и минусы не равны 0" << std::endl;
    }
}