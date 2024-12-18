#include "twodaypackage.h"

// constructors
TwoDayPackage::TwoDayPackage() : PACKAGE(), flatFee(10.99) {}

TwoDayPackage::TwoDayPackage(const string& n, const string& a, const string& c, const string& s, const string& z, double w, double r, double f) 
    : PACKAGE(n, a, c, s, z, w, r), flatFee(f) {}

// setter
void TwoDayPackage::setFlatFee(double f) {
    flatFee = f;
}

// getter
double TwoDayPackage::getFlatFee() const {
    return flatFee;
}

// override
double TwoDayPackage::calculateCost() const{
    return PACKAGE::calculateCost() + flatFee;
}