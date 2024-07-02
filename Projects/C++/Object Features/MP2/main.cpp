/*Mustafa Shah*/

#include <iostream>
#include "twodaypackage.h"
#include "overnightpackage.h"

using namespace std;

int main()
{
    TwoDayPackage p1("Mustafa Shah 2DAY", "", "New York", "NY", "12345", 16, 0.5, 10.99);
    p1.setAddress("123 John St");
    p1.infoOut();
    OvernightPackage p2("Mustafa Shah 1DAY", "123 John St", "New York", "NY", "12345", 16, 0.5, 0);
    p2.setFeePerOunce(.75);
    p2.infoOut();
    return 0;
}