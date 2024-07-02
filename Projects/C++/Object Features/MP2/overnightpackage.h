#include "package.h"
#include <iostream>

using namespace std;

class OvernightPackage : public PACKAGE {
    private:
        double feePerOunce;
    
    public:
        OvernightPackage(); 
        OvernightPackage(const string& n, const string& a, const string& c, const string& s, const string& z, double w, double r, double f);
        void setFeePerOunce(double feePerOunce);
        double getFeePerOunce() const;
        double calculateCost() const override;
};