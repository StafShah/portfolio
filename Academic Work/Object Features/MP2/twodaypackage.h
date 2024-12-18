#include "package.h"
#include <iostream>

using namespace std;

class TwoDayPackage : public PACKAGE {
    private:
        double flatFee;
    
    public:
        TwoDayPackage(); 
        TwoDayPackage(const string& n, const string& a, const string& c, const string& s, const string& z, double w, double r, double f);
        void setFlatFee(double f);
        double getFlatFee() const;
        double calculateCost() const override;
};