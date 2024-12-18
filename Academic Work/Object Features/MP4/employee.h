#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "person.h"

class Employee : public Person {
    private:
        int officeNumber;
        double salary;
    
    public:
        Employee();
        Employee(const string& n, const string& a, const string& p, const string& e, int officeNum, double sal);
        void setOfficeNumber(int officeNum);
        void setSalary(double sal);
        int getOfficeNumber() const;
        double getSalary() const;
        void infoOut() const override;
};

#endif
