#include <iostream>
using namespace std;

class Attendee {

    private:
    string typeAttendee;
    string name;
    string occupation;
    string company;

    public:

    Attendee();

    // GETTERS
    void getTypeAttendee();
    void getName();
    void getOccupation();
    void getCompany();
    
    // SETTERS

    string setTypeAttendee(string);
    string settName(string);
    string setOccupation(string);
    string setCompany(string);

};