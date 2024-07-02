#include "employee.h"
#include <iostream>

Employee::Employee() : Person(), officeNumber(0), salary(0.0) {}

Employee::Employee(const string& n, const string& a, const string& p, const string& e, int officeNum, double sal)
    : Person(n, a, p, e), officeNumber(officeNum), salary(sal) {}

void Employee::setOfficeNumber(int officeNum) {
    officeNumber = officeNum;
}

void Employee::setSalary(double sal) {
    salary = sal;
}

int Employee::getOfficeNumber() const {
    return officeNumber;
}

double Employee::getSalary() const {
    return salary;
}

void Employee::infoOut() const {
    Person::infoOut();
    cout << "Office Number: " << officeNumber << endl;
}
