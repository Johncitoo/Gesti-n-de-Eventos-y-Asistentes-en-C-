#pragma once

#include <iostream>

#include "Event.h"

using namespace std;

Event::Event(string type,string location,string topic,float duration){
    this->type = type;
    this->location = location;
    this->topic = topic;
    this->duration = duration;
}


void Event::addAttendee(Attendee attendee) {
    if (listAttendee.size() < 201) {
        listAttendee.push_back(attendee);
    } else {
        cout << "No se pueden agregar más asistentes, lista llena" << endl;
    }
}

