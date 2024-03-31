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

    // GETTERS
    
    string getType();
    string geLocation();
    string getTopic();
    float getDuration();
    vector<Attendee> getAttendees();
    // SETTERS

    void setType(string);
    void setLocation(string);
    void setTopic(string);
    void setDuration(float);

    void addAttendee(Attendee);


};