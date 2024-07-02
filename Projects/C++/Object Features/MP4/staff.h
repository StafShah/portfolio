#ifndef STAFF_H
#define STAFF_H

#include "employee.h"
#include <string>
using namespace std;

class Staff : public Employee {
    private:
        string title;
    
    public:
        Staff();
        Staff(const string& n, const string& a, const string& p, const string& e, int officeNum, double sal, const string& t);
        void setTitle(const string& t);
        string getTitle() const;
        void infoOut() const override;
};

#endif
