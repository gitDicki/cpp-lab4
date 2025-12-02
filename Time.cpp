#include "Time.h"
#include <limits>
#include <string>

Time::Time(){
    this->hours = 0; 
    this->minutes = 0;
}

Time::Time(unsigned int h, unsigned int m) {
    this->hours = h + m / 60;
    this->minutes = m % 60;
}

Time::Time(unsigned int h) : hours(h), minutes(0) {}

Time& Time::operator++() {
    minutes++;
    if (minutes >= 60) {
        minutes -= 60;
        hours++;
    }
    return *this;
}

Time Time::operator++(int) {
    Time temp = *this;
    ++(*this);
    return temp;
}

Time& Time::operator--() {
    if (minutes > 0) {
        minutes--;
    } else if (hours > 0) {
        hours--;
        minutes = 59;
    }

    return *this;
}

Time Time::operator--(int) {
    Time temp = *this;
    --(*this);
    return temp;
}

Time::operator short int() const {
    return static_cast<short int>(hours);
}

Time::operator bool() const {
    return (hours != 0 || minutes != 0);
}

Time Time::operator+(unsigned int mins) const {
    unsigned int totalMinutes = this->minutes + mins;
    unsigned int totalHours = this->hours + totalMinutes / 60;
    totalMinutes = totalMinutes % 60;
    return Time(totalHours, totalMinutes);
}

Time Time::operator-(unsigned int mins) const {
    long long totalCurrentMinutes = static_cast<long long>(this->hours) * 60 + this->minutes;
    long long resultMinutes = totalCurrentMinutes - mins;

    if (resultMinutes < 0) {
        return Time(0, 0);
    }

    unsigned int newHours = resultMinutes / 60;
    unsigned int newMinutes = resultMinutes % 60;
    return Time(newHours, newMinutes);
}

Time Time::add_minutes(unsigned int min) {
    return *this + min;;
}

std::ostream& operator<<(std::ostream& os, const Time& t) {
    os << t.hours << "h " << t.minutes << "m";
    return os;
}