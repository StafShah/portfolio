#include "overnightpackage.h"

// constructors
OvernightPackage::OvernightPackage() : PACKAGE(), feePerOunce(0.50) {}

OvernightPackage::OvernightPackage(const string& n, const string& a, const string& c, const string& s, const string& z, double w, double r, double f)
    : PACKAGE(n, a, c, s, z, w, r), feePerOunce(f) {}

// setter
void OvernightPackage::setFeePerOunce(double f) {
    feePerOunce = f;
}

// getter
double OvernightPackage::getFeePerOunce() const {
    return feePerOunce;
}

// override
double OvernightPackage::calculateCost() const{
    return PACKAGE::calculateCost() + (feePerOunce * getWeight());
}