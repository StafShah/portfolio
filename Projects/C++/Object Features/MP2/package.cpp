#include <iostream>
#include "package.h"

using namespace std;

// constructors
PACKAGE::PACKAGE() {
    name = "";
    address = "";
    city = "";
    state = "";
    zipcode = "";
    weight = 0;
    rate = 0;
}

PACKAGE::PACKAGE(const string& n, const string& a, const string& c, const string& s, const string& z, double w, double r) {
    name = n;
    address = a;
    city = c;
    state = s;
    zipcode = z;
    weight = w;
    rate = r;
}

// setters
void PACKAGE::setName(const string& n) {
    name = n;
}

void PACKAGE::setAddress(const string& a) {
    address = a;
}

void PACKAGE::setCity(const string& c) {
    city = c;
}

void PACKAGE::setState(const string& s) {
    state = s;
}

void PACKAGE::setZipcode(const string& z) {
    zipcode = z;
}

void PACKAGE::setWeight(double w) {
    weight = w;
}

void PACKAGE::setRate(double r) {
    rate = r;
}

// getters
string PACKAGE::getName() const {
    return name;
}

string PACKAGE::getAddress() const {
    return address;
}

string PACKAGE::getCity() const {
    return city;
}

string PACKAGE::getState() const {
    return state;
}

string PACKAGE::getZipcode() const {
    return zipcode;
}

double PACKAGE::getWeight() const {
    return weight;
}

double PACKAGE::getRate() const {
    return rate;
}

// other
double PACKAGE::calculateCost() const {
    return weight * rate;
}

void PACKAGE::infoOut() const {
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
    cout << city << ", " << state << " " << zipcode << endl;
    cout << "Cost: $" << calculateCost() << endl;
}