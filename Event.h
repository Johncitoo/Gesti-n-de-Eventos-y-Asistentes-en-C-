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
    vector<Attendee> attendeeList;
    
    public:

    void addAttendee(Attendee);


};