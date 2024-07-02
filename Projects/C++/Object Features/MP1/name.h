#include <iostream>

using namespace std;

class Name {
    private:
        string first, father, family;
    
    public:
        Name();
        Name(const string f, const string r, const string m);
        void setParams(const string f, const string r, const string m);
        string getFirst() const;
        string getFather() const;
        string getFamily() const;
        void infoOut() const;
};