#pragma once

#include "Attendee.h"
#include <iostream>
using namespace std;

Attendee::Attendee(string typeAttendee,string name,string occupation,string company){
    this->name = name;
    this->typeAttendee = typeAttendee;
    this->occupation = occupation;
    this->company = company;
    
}

string Attendee::getTypeAttendee() {
    return typeAttendee;
}
string Attendee::getName() {
    return name;
}
string Attendee::getOccupation() {
    return occupation;
}
string Attendee::getCompany() {
    return company;
}





