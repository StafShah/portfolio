#include <iostream>
#include "licenserestrictions.h"

using namespace std;

LicenseRestrictions::LicenseRestrictions() {
    number = 0;
    restriction = "";
}

LicenseRestrictions::LicenseRestrictions(const int n, const string r) {
    number = n;
    restriction = r;
}

void LicenseRestrictions::setParams(const int n, const string r) {
    number = n;
    restriction = r;
}

int LicenseRestrictions::getNumber() const {
    return number;
}

string LicenseRestrictions::getRestriction() const {
    return restriction;
}

void LicenseRestrictions::infoOut() const {
    cout << number << " ----- " << restriction << endl;
}