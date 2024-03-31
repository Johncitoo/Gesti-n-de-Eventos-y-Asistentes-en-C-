#pragma once

#include <iostream>

#include "Event.h"

using namespace std;

/**
 * The Event constructor initializes the type, location, topic, and duration of an event.
 * 
 * @param type The `type` parameter in the `Event` constructor is used to specify the type or category
 * of the event. It could be a conference, workshop, seminar, meeting, etc.
 * @param location Location is a parameter in the Event constructor that represents the physical
 * location where the event will take place. It could be a specific venue, room, or any other place
 * where the event is scheduled to occur.
 * @param topic The "topic" parameter in the Event constructor refers to the subject or theme of the
 * event. It could be the main focus or discussion point of the event.
 * @param duration Duration is a float value representing the length of the event in hours.
 */
Event::Event(string type,string location,string topic,float duration){
    this->type = type;
    this->location = location;
    this->topic = topic;
    this->duration = duration;
}


/**
 * The function `addAttendee` adds an attendee to a list if the list is not full, otherwise it displays
 * a message indicating that the list is full.
 * 
 * @param attendee The `addAttendee` function in the `Event` class is used to add an attendee to the
 * list of attendees for that event. The function checks if the number of attendees in the list is less
 * than 201 before adding a new attendee. If the list is already full (201 attendees),
 */
void Event::addAttendee(Attendee attendee) {
    if (listAttendee.size() < 201) {
        listAttendee.push_back(attendee);

    } else {
        cout << "No se pueden agregar más asistentes, lista llena" << endl;
    }
}

// Getters

/**
 * This function returns the type of the event.
 * 
 * @return The function `getType()` is returning the `type` member variable of the `Event` class, which
 * is a string.
 */
string Event::getType() { return type; }

/**
 * This function returns the location of an event.
 * 
 * @return The `location` variable is being returned.
 */
string Event::geLocation() { return location; }

/**
 * This function returns the topic of the event.
 * 
 * @return The `topic` variable is being returned.
 */
string Event::getTopic() { return topic; }

/**
 * The function `getDuration` returns the duration of an event.
 * 
 * @return The `duration` variable is being returned.
 */
float Event::getDuration() { return duration; }

/**
 * The function `getDuration` returns the list of attendee of event.
 * 
 * @return The `listAttendee` variable is being returned.
 */
vector<Attendee> Event::getAttendees(){return listAttendee;}

// Setters

/**
 * The function `setType` sets the type of an event.
 * 
 * @param type The `setType` function in the `Event` class is used to set the type of the event. The
 * `type` parameter is a string that represents the type of the event, such as "birthday", "meeting",
 * "concert", etc.
 */
void Event::setType(string type) { this->type = type; }

/**
 * The function `setLocation` in the `Event` class sets the location of the event.
 * 
 * @param location The `location` parameter is a string that represents the location where the event
 * will take place.
 */
void Event::setLocation(string location) { this->location = location; }

/**
 * This function sets the topic of an event.
 * 
 * @param topic The `setTopic` function is a member function of a class named `Event`. It takes a
 * `string` parameter named `topic` and assigns the value of `topic` to the `topic` member variable of
 * the `Event` class using the `this` pointer.
 */
void Event::setTopic(string topic) { this->topic = topic; } 

/**
 * The function `setDuration` in C++ sets the duration of an event.
 * 
 * @param duration The `duration` parameter in the `setDuration` method is a float type parameter that
 * represents the duration of an event.
 */
void Event::setDuration(float duration) { this->duration = duration; }
