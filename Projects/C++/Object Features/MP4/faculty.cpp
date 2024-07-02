#include "faculty.h"
#include <iostream>

Faculty::Faculty() : Employee(), officeHours(""), rank("") {}

Faculty::Faculty(const string& n, const string& a, const string& p, const string& e, int officeNum, double sal, const string& hours, const string& r)
    : Employee(n, a, p, e, officeNum, sal), officeHours(hours), rank(r) {}

void Faculty::setOfficeHours(const string& hours) {
    officeHours = hours;
}

void Faculty::setRank(const string& r) {
    rank = r;
}

string Faculty::getOfficeHours() const {
    return officeHours;
}

string Faculty::getRank() const {
    return rank;
}

void Faculty::infoOut() const {
    Person::infoOut();
    cout << rank << endl;
    cout << officeHours << endl;
}
