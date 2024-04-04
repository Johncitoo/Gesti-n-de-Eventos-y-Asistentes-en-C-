#include <iostream>
using namespace std;

class Attendee {

    private:
    string typeAttendee;
    string name;
    string occupation;
    string company;
    int age;

    public:

    Attendee(string,string,string,string,int);

    // GETTERS
    string getTypeAttendee();
    string getName();
    string getOccupation();
    string getCompany();
    int getAge();

    // SETTERS

    void setTypeAttendee(string);
    void setName(string);
    void setOccupation(string);
    void setCompany(string);

};