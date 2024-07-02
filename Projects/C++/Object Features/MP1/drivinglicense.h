#include <iostream>

using namespace std;

class DrivingLicense {
private:
    string name;
    string licenseCenter;
    string nationality;
    int licenseNumber;
    int nationalNumber;
    string issueDate;
    string birthDate;
    string expiryDate;
    string gender;
    int type;
    string address;
    int restriction;
    string bloodGroup;
    static int howManyLicenses;

public:
    DrivingLicense();
    ~DrivingLicense();
    DrivingLicense(const string n, const string lc, const string nat, const int ln, const int nn, const string id, const string bd, const string ed, const string g, const int t, const string a, const int r, const string bg);
    void setParams(const string n, const string lc, const string nat, const int ln, const int nn, const string id, const string bd, const string ed, const string g, const int t, const string a, const int r, const string bg);
    string getName() const;
    string getLicenseCenter() const;
    string getNationality() const;
    int getLicenseNumber() const;
    int getNationalNumber() const;
    string getIssueDate() const;
    string getBirthDate() const;
    string getExpiryDate() const;
    string getGender() const;
    int getType() const;
    string getAddress() const;
    int getRestriction() const;
    string getBloodGroup() const;
    void infoOut() const;
    static int getHowManyLicenses();
};