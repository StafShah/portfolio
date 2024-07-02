/*Mustafa Shah*/
#include <iostream>
#include "person.h"
#include "student.h"
#include "employee.h"
#include "faculty.h"
#include "staff.h"

using namespace std;

int main()
{
    cout << "Person" << endl;
    Person p("John Doe", "123 Main St", "734xxxxxxx", "johndoe@example.com");
    p.infoOut();
    cout << "\nStudent" << endl;
    Student q("Khaled Mansour", "555 Washtenaw Ave", "248xxxxxxx", "kmansour@wccnet.edu", "Senior");
    q.infoOut();
    cout << "\nEmployee" << endl;
    Employee r("Mustafa Shah", "327 Main St", "734xxxxxxx", "mkshah@wccnet.edu", 505, 100000);
    r.infoOut();
    cout << "\nFaculty" << endl;
    Faculty s("Michael Jackson", "999 Moonwalk St", "619xxxxxxx", "mjackson@wccnet.edu", 506, 50000000, "Singer", "8AM - 8PM");
    s.infoOut();
    cout << "\nStaff" << endl;
    Staff t("Donald Trump", "555 Trump Tower", "555xxxxxxx", "donaldjtrump@president.com", 900, 0, "Candidate");
    t.infoOut();
    return 0;
}