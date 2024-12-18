#include <iostream>
#include "name.h"

using namespace std;

Name::Name() {
    first = "", father = "", family = "";
}

Name::Name(const string f, const string r, const string m) {
    first = f;
    father = r;
    family = m;
}

void Name::setParams(const string f, const string r, const string m) {
    first = f;
    father = r;
    family = m;
}

string Name::getFirst() const {
    return first;
}

string Name::getFather() const {
    return father;
}

string Name::getFamily() const {
    return family;
}

void Name::infoOut() const{
    cout << first << " " << father << " " << family << endl;
}