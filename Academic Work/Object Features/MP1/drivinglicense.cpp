#include <iostream>
#include "drivinglicense.h"

using namespace std;

int DrivingLicense::howManyLicenses = 0;

DrivingLicense::DrivingLicense() {
    name = "N/A";
    licenseCenter = "N/A";
    nationality = "N/A";
    licenseNumber = 0;
    nationalNumber = 0;
    issueDate = "N/A";
    birthDate = "N/A";
    expiryDate = "N/A";
    gender = "N/A";
    type = 0;
    address = "N/A";
    restriction = 0;
    bloodGroup = "N/A";
    howManyLicenses++;
}

DrivingLicense::~DrivingLicense() {
    howManyLicenses--;
    cout << "Number of licenses after destruction: " << howManyLicenses << endl;
}

DrivingLicense::DrivingLicense(const string n, const string lc, const string nat, const int ln, const int nn, const string id, const string bd, const string ed, const string g, const int t, const string a, const int r, const string bg) {
    name = n;
    licenseCenter = lc;
    nationality = nat;
    licenseNumber = ln;
    nationalNumber = nn;
    issueDate = id;
    birthDate = bd;
    expiryDate = ed;
    gender = g;
    type = t;
    address = a;
    restriction = r;
    bloodGroup = bg;
    howManyLicenses++;
}

void DrivingLicense::setParams(const string n, const string lc, const string nat, const int ln, const int nn, const string id, const string bd, const string ed, const string g, const int t, const string a, const int r, const string bg) {
    name = n;
    licenseCenter = lc;
    nationality = nat;
    licenseNumber = ln;
    nationalNumber = nn;
    issueDate = id;
    birthDate = bd;
    expiryDate = ed;
    gender = g;
    type = t;
    address = a;
    restriction = r;
    bloodGroup = bg;
}

string DrivingLicense::getName() const { return name; }
string DrivingLicense::getLicenseCenter() const { return licenseCenter; }
string DrivingLicense::getNationality() const { return nationality; }
int DrivingLicense::getLicenseNumber() const { return licenseNumber; }
int DrivingLicense::getNationalNumber() const { return nationalNumber; }
string DrivingLicense::getIssueDate() const { return issueDate; }
string DrivingLicense::getBirthDate() const { return birthDate; }
string DrivingLicense::getExpiryDate() const { return expiryDate; }
string DrivingLicense::getGender() const { return gender; }
int DrivingLicense::getType() const { return type; }
string DrivingLicense::getAddress() const { return address; }
int DrivingLicense::getRestriction() const { return restriction; }
string DrivingLicense::getBloodGroup() const { return bloodGroup; }

void DrivingLicense::infoOut() const {
    cout << "Name: " << name << "\nLicense Center: " << licenseCenter
         << "\nNationality: " << nationality << "\nLicense Number: " << licenseNumber
         << "\nNational Number: " << nationalNumber << "\nIssue Date: " << issueDate
         << "\nBirth Date: " << birthDate << "\nExpiry Date: " << expiryDate
         << "\nGender: " << gender << "\nType: " << type << "\nAddress: " << address
         << "\nRestriction: " << restriction << "\nBlood Group: " << bloodGroup << endl;
}

int DrivingLicense::getHowManyLicenses() {
    return howManyLicenses;
}