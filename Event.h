#pragma once

#include "Attendee.cpp"
#include <iostream>
#include <vector>
using namespace std;

class Event {

    private:

    string type;
    string location;
    string topic;
    float duration;
    vector<Attendee> listAttendee;
    
    public:

    Event(string,string,string,float);

    void addAttendee(Attendee);


};