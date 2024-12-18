#ifndef FACULTY_H
#define FACULTY_H

#include "employee.h"

class Faculty : public Employee {
    private:
        string officeHours;
        string rank;
    
    public:
        Faculty();
        Faculty(const string& n, const string& a, const string& p, const string& e, int officeNum, double sal, const string& hours, const string& r);
        void setOfficeHours(const string& hours);
        void setRank(const string& r);
        string getOfficeHours() const;
        string getRank() const;
        void infoOut() const override;
};

#endif
