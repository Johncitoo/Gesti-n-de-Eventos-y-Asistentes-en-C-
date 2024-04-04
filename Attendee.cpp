#pragma once

#include "Attendee.h"
#include <iostream>
using namespace std;

Attendee::Attendee(string typeAttendee,string name,string occupation,string company,int age){
    this->name = name;
    this->typeAttendee = typeAttendee;
    this->occupation = occupation;
    this->company = company;
    this->age = age;
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

int Attendee::getAge(){
    return age;
}




