
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "Event.cpp"
#include "Attendee.cpp"

using namespace std;

// Funciones

/** The function `readTxt` reads event information from a text file and populates a vector of Event
 * objects with corresponding Attendee objects.
 * 
 * @param listEvent `listEvent` is a vector of `Event` objects. The function `readTxt` reads data from
 * a file named "Info.txt" and populates this vector with events and their corresponding attendees.
 * 
 * @return nothing
 * 
 */
void readTxt(vector<Event>& listEvent);

void menu(vector<Event>& listEvent);

int main()
{
    vector<Event> listEvent;

    readTxt(listEvent);
    menu(listEvent);

    return 0;
}


void readTxt(vector<Event>& listEvent) {

    // Opening the file
    ifstream arch("Info.txt");

    // File verification
    if (!arch.is_open()) {
        cout << "ERROR!!! NO SE ENCONTRO EL ARCHIVO" << endl;
        return;
    }

    string line;

    // Event
    string type;
    string location;
    string topic;
    float duration;

    string part;
    vector<string> parts;

    // Attendee
    string typeAttendee;
    string name;
    string occupation;
    string company;
    

    while (getline(arch, line)) {
        
        stringstream ss(line);

        while (getline(ss, part, ';')) {
            parts.push_back(part);
        }

        type = string(parts[0]);
        location = parts[1];
        topic = parts[2];
        duration = stof(parts[3]);

        Event event(type,location,topic,duration);
        listEvent.push_back(event);

        for (int i = 0; i < stoi(parts[4]); i++)
        {

            parts.clear();
            getline(arch, line);
            stringstream attendeeLine(line);

            while (getline(attendeeLine, part, '-')) {
                parts.push_back(part);
            }

            typeAttendee = part[0];
            name = part[1];
            occupation = part[2];
            company = part[3];

            Attendee attendee(typeAttendee,name,occupation,company);
            event.addAttendee(attendee);
        }
        

        
    }


};
