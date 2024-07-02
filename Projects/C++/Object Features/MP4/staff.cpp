#include "staff.h"
#include <iostream>

Staff::Staff() : Employee(), title("") {}

Staff::Staff(const string& n, const string& a, const string& p, const string& e, int officeNum, double sal, const string& t)
    : Employee(n, a, p, e, officeNum, sal), title(t) {}

void Staff::setTitle(const string& t) {
    title = t;
}

string Staff::getTitle() const {
    return title;
}

void Staff::infoOut() const {
    Person::infoOut();
    cout << title << endl;
}
