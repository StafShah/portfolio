#pragma once
#include <iostream>

using namespace std;

class Person {
    private:
        string name, address, phone, email;
        
    public:
        Person();
        Person(const string& n, const string& a, const string& p, const string& e);
        void setName(const string& n);
        void setAddress(const string& a);
        void setPhone(const string& p);
        void setEmail(const string& e);
        string getName() const;
        string getAddress() const;
        string getPhone() const;
        string getEmail() const;
        virtual void infoOut() const;
};