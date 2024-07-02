#include "student.h"
#include <iostream>

Student::Student() : Person(), status("Freshman") {}

Student::Student(const string& n, const string& a, const string& p, const string& e, const string& s)
    : Person(n, a, p, e), status(s) {}

void Student::setStatus(const string& s) {
    status = s;
}

string Student::getStatus() const {
    return status;
}

void Student::infoOut() const {
    Person::infoOut();
    cout << "Status: " << status << endl;
}

// void Student::displayStatus() const {
//     cout << "Status: " << status << endl;
// }
