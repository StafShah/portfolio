#ifndef PACKAGE_H
#define PACKAGE_H

#include <iostream>

using namespace std;

class PACKAGE {
    private:
        string name, address, city, state, zipcode;
        double weight, rate;
    
    public:
        PACKAGE();
        PACKAGE(const string& n, const string& a, const string& c, const string& s, const string& z, double w, double r);
        void setName(const string& n);
        void setAddress(const string& a);
        void setCity(const string& c);
        void setState(const string& s);
        void setZipcode(const string& z);
        void setWeight(double w);
        void setRate(double r);
        string getName() const;
        string getAddress() const;
        string getCity() const;
        string getState() const;
        string getZipcode() const;
        double getWeight() const;
        double getRate() const;
        virtual double calculateCost() const;
        void infoOut() const;
};


#endif // PACKAGE_H