#include <iostream>

using namespace std;

class Date {
    private:
        int day, month, year;
    
    public:
        Date();
        Date(const int d, const int m, const int y);
        void setParams(const int d, const int m, const int y);
        int getDay() const;
        int getMonth() const;
        int getYear() const;
        void infoOut() const;
};