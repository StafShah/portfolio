#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"

class Student : public Person {
    private:
        string status;
        
    public:
        Student();
        Student(const string& n, const string& a, const string& p, const string& e, const string& s);
        void setStatus(const string& s);
        string getStatus() const;
        void infoOut() const override;
};

#endif