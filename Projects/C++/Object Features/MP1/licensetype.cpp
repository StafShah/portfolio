#include <iostream>
#include "licensetype.h"

using namespace std;

LicenseType::LicenseType() {
    type = 4;
    description = "Private passenger vehicle";
}

LicenseType::LicenseType(const int t, const string d) {
    type = t;
    description = d;
}

void LicenseType::setParams(const int t, const string d) {
    type = t;
    description = d;
}

int LicenseType::getType() const {
    return type;
}

string LicenseType::getDescription() const {
    return description;
}

void LicenseType::infoOut() const {
    cout << type << " ----- " << description << endl;
}