#include <iostream>
#include "date.h"

using namespace std;

Date::Date() {
    day = 1;
    month = 1;
    year = 1990;
}

Date::Date(const int d, const int m, const int y) {
    day = d;
    month = m;
    year = y;
}

void Date::setParams(const int d, const int m, const int y) {
    day = d;
    month = m;
    year = y;
}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

void Date::infoOut() const {
    cout << day << '/' << month << '/' << year << endl;
}