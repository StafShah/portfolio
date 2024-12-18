#include "person.h"
#include <iostream>

Person::Person() {
    name = "";
    address = "";
    phone = "";
    email = "";
}

Person::Person(const string& n, const string& a, const string& p, const string& e) {
    name = n;
    address = a;
    phone = p;
    email = e;
}

void Person::setName(const string& n) {
    name = n;
}

void Person::setAddress(const string& a) {
    address = a;
}

void Person::setPhone(const string& p) {
    phone = p;
}

void Person::setEmail(const string& e) {
    email = e;
}

string Person::getName() const {
    return name;
}

string Person::getAddress() const {
    return address;
}

string Person::getPhone() const {
    return phone;
}

string Person::getEmail() const {
    return email;
}

void Person::infoOut() const {
    cout << name << endl;
    cout << address << endl;
    cout << email << ", " << phone << endl;
}