#ifndef TIME_H
#define TIME_H

#include <iostream>

class Time {
public:
    unsigned int hours;
    unsigned int minutes;

    Time();
    Time(unsigned int h, unsigned int m);
    Time(unsigned int h);

    Time& operator++();
    Time operator++(int);

    Time& operator--();
    Time operator--(int);

    explicit operator short int() const;
    explicit operator bool() const;

    Time operator+(unsigned int mins) const;
    Time operator-(unsigned int mins) const;

    Time add_minutes(unsigned int min);
    friend std::ostream& operator<<(std::ostream& os, const Time& t);
};

#endif