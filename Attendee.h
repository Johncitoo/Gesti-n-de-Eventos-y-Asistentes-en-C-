#include <iostream>
using namespace std;

class Attendee {

    private:
    string typeAttendee;
    string name;
    string occupation;
    string company;

    public:

    Attendee(string,string,string,string);

    // GETTERS
    string getTypeAttendee();
    string getName();
    string getOccupation();
    string getCompany();
    
    // SETTERS

    void setTypeAttendee(string);
    void settName(string);
    void setOccupation(string);
    void setCompany(string);

};