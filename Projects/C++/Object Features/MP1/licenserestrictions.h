#include <iostream>

using namespace std;

class LicenseRestrictions {
    private:
        int number;
        string restriction;
    
    public:
        LicenseRestrictions();
        LicenseRestrictions(const int n, const string r);
        void setParams(const int n, const string r);
        int getNumber() const;
        string getRestriction() const;
        void infoOut() const;
};