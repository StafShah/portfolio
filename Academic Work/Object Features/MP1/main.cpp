/*Mustafa Shah*/
#include <iostream>
#include "name.h"
#include "date.h"
#include "licensetype.h"
#include "licenserestrictions.h"
#include "drivinglicense.h"

using namespace std;

int main()
{
    // name demo
    cout << "Name" << endl;
    Name name("Mustafa", "Kamal", "Shah");
    cout << "Initialized Name: ";
    name.infoOut();
    name.setParams("Mustafa", "Kemal", "Pasha");
    cout << "Name Changed with setParams: ";
    name.infoOut();
    
    // date demo
    cout << "\nDate" << endl;
    Date date(7, 1, 2005);
    cout << "Initialized Date: ";
    date.infoOut();
    date.setParams(1, 2, 2022);
    cout << "Date Changed with setParams: ";
    date.infoOut();
    
    // license type demo
    cout << "\nLicense Type" << endl;
    LicenseType licensetype(7, "Buses");
    cout << "Initialized License Type: ";
    licensetype.infoOut();
    licensetype.setParams(1, "All types of motorcycles");
    cout << "License Type Changed with setParams: ";
    licensetype.infoOut();
    
    // license restrictions demo
    cout << "\nLicense Restrictions" << endl;
    LicenseRestrictions licenserestrictions(1, "Glasses");
    cout << "Initialized License Restrictions: ";
    licenserestrictions.infoOut();
    licenserestrictions.setParams(4, "Disabled");
    cout << "License Restrictions Changed with setParams: ";
    licenserestrictions.infoOut();
    
    // driving license demo
    cout << "\nDriving License" << endl;
    DrivingLicense drivinglicense1("Mustafa Shah", "Canton SOS", "American", 90000000, 12345678, "5/10/2022", "7/1/2005", "5/10/2025", "Male", 4, "123 John St", 1, "O-");
    cout << "License 1 Info \n";
    drivinglicense1.infoOut();
    cout << "Current Licenses: " << drivinglicense1.getHowManyLicenses() << endl;
    drivinglicense1.setParams("Khaled Mansour", "Washtenaw SOS", "American", 8000000, 12345677, "7/6/2022", "7/5/1995", "7/6/2025", "Male", 0, "124 John St", 0, "O+");
    cout << "License 1 Changed with setParams " << endl;
    drivinglicense1.infoOut();
    DrivingLicense drivinglicense2;
    cout << "Current Licenses with New Added: " << drivinglicense2.getHowManyLicenses() << endl;
    
    return 0;
}