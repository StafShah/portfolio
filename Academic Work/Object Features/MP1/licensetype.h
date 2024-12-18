#include <iostream>

using namespace std;

class LicenseType {
    private:
        int type;
        string description;
    
    public:
        LicenseType();
        LicenseType(const int t, const string d);
        void setParams(const int t, const string d);
        int getType() const;
        string getDescription() const;
        void infoOut() const;
};