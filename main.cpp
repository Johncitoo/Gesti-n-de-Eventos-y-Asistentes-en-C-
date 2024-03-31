
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <limits>

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

void writeTxt(vector<Event>& listEvent);

void options(vector<Event>& listEvent,int option);

int main()
{
    cout<< "Hola mundo1"<<endl;
    vector<Event> listEvent;
    cout<< "Hola mundo2"<<endl;
    readTxt(listEvent);
    cout<< "Hola mundo3"<<endl;
    writeTxt(listEvent);
    menu(listEvent);

    
    for (size_t i = 0; i < listEvent.size(); i++)
    {
        cout<<"------"<<listEvent[i].getType()<<"------"<<endl;

        vector<Attendee> attendeers = listEvent[i].getAttendees();

        cout<<"-----Participantes:-------"<<endl;
        
        for (size_t j = 0; j < attendeers.size(); j++)
        {
            
            cout<<listEvent[i].getAttendees()[j].getName()<<endl;
        }
        cout<<attendeers.size()<<endl;
    }
    
    cout<<"fin"<<endl;

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
    string* type = new string;
    string* location = new string;
    string* topic = new string;
    float* duration = new float;

    string* part = new string;
    vector<string> parts;

    // Attendee
    string* typeAttendee = new string;
    string* name = new string;
    string* occupation = new string;
    string* company = new string;
    

    while (getline(arch, line)) {

        stringstream ss(line);
        
        while (getline(ss, *part, ';')) {
            parts.push_back(*part);

        }


        *type = string(parts[0]);
        *location = parts[1];
        *topic = parts[2];
        *duration = stof(parts[3]);

        Event event(*type,*location,*topic,*duration);
        


        
        for (int i = 0; i < stoi(parts[4]); i++)
        {

            parts.clear();
            getline(arch, line);
            stringstream attendeeLine(line);


            while (getline(attendeeLine, *part, '-')) {
                parts.push_back(*part);

            }

            *typeAttendee = parts[0];
            *name = parts[1];
            *occupation = parts[2];
            *company = parts[3];


            Attendee attendee(*typeAttendee,*name,*occupation,*company);
            event.addAttendee(attendee);

            parts.clear();
        }

        listEvent.push_back(event);
        

        
    }
    //Delete
    delete type ;
    delete location;
    delete topic;
    delete duration;

    delete part;

    // Attendee
    delete typeAttendee;
    delete name;
    delete occupation;
    delete company;
    
    arch.close();

    
};
//This function is responsible for writing in the txt file all the data that the list of events has 
//and also the attendees of these events

void writeTxt(vector<Event>& listEvent){

    ofstream file;

    file.open("Info.txt",ios::out); //open the file

    if (file.fail())
    {
        cout<< "Error al abrir el archivo"<<endl;
        exit(1);
    }
    //loops through the events and writes them to the txt
    for (size_t i = 0; i < listEvent.size(); i++)
    {
        
        file<<listEvent[i].getType()<<";"<<listEvent[i].geLocation()<<";"<<listEvent[i].getTopic()<<";"<<listEvent[i].getDuration()<<";"<<listEvent[i].getAttendees().size()<<endl;
        
        vector<Attendee> attendeers = listEvent[i].getAttendees();

        //write the event attendees in the txt
        for (size_t j = 0; j < attendeers.size(); j++)
        {
            
            file<<attendeers[j].getTypeAttendee()<<"-"<<attendeers[j].getName()<<"-"<<attendeers[j].getOccupation()<<"-"<<attendeers[j].getCompany()<<endl;
        }

    }

};
//This function is responsible for managing the procedures that must be carried out given the selection of one of the menu options.
void options(vector<Event>& listEvent,int option){

    switch (option)
    {
    case 1: {

    
        cout<<"Ingrese los datos del evento:"<<endl;
        cout<<"Tipo:"<<endl;

        string type;

        cin>>type;

        cout<<"Ubicacion"<<endl;

        string location;

        cin>>location;

        cout<<"Tema"<<endl;
        string topic;
        cin>>topic;

        cout<<"Duracion"<<endl;
        float duration;
        cin>>duration;

        Event event(type,location,topic,duration);

        cout<<"Ingrese la cantidad de asistentes que asistiran al evento:"<<endl;
        //a sweep of the entered data is carried out due to an error that occurred
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int quantityAttendees;
        cin>>quantityAttendees;
        //iterates by the number of attendees who want to register for the event
        for (size_t i = 0; i < quantityAttendees; i++)
        {
            
            cout<<"Ingrese los datos del asistente:"<<endl;
            cout<<"Nombre:"<<endl;

            string name;

            cin>>name;

            cout<<"Tipo de asistente"<<endl;

            string typeAttendee;

            cin>>typeAttendee;

            cout<<"Ocupacion"<<endl;
            string occupation;
            cin>>occupation;

            cout<<"Compañia"<<endl;
            string company;
            cin>>company;

            Attendee attendee(typeAttendee,name,occupation,company);
            event.addAttendee(attendee);

        }
        //The event is added with all its data to the list and all the data in the list is written to the txt.
        listEvent.push_back(event);
        writeTxt(listEvent);

        break;
    }
    case 2:{

        cout<<"En que evento desea registrar nuevos asistentes?"<<endl;
        //print the events whit his information.
        for (size_t i = 0; i < listEvent.size(); i++)
    {
        cout<<i<<") "<<listEvent[i].getType()<<";"<<listEvent[i].geLocation()<<";"<<listEvent[i].getTopic()<<";"<<listEvent[i].getDuration()<<";"<<listEvent[i].getAttendees().size()<<endl;

    }
        int option;
        cin>>option;

        cout<<listEvent.size()-1<<"---"<<option<<endl;
    //error control in case of entering invalid data
    while (option>listEvent.size()-1 || option<0)
    {
        cout<<"Error, ingrese una opcion valida"<<endl;
        for (size_t i = 0; i < listEvent.size(); i++)
    {
        cout<<i<<") "<<listEvent[i].getType()<<";"<<listEvent[i].geLocation()<<";"<<listEvent[i].getTopic()<<";"<<listEvent[i].getDuration()<<";"<<listEvent[i].getAttendees().size()<<endl;

    }
        cin>>option;
    }
    
        cout<<"Ingrese la cantidad de asistentes que desea registrar:"<<endl;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int quantityAttendees;
        cin>>quantityAttendees;
        //iterates by the number of attendees who want to register for the event
        for (size_t i = 0; i < quantityAttendees; i++)
        {
            
            cout<<"Ingrese los datos del asistente:"<<endl;
            cout<<"Nombre:"<<endl;

            string name;

            cin>>name;

            cout<<"Tipo de asistente"<<endl;

            string typeAttendee;

            cin>>typeAttendee;

            cout<<"Ocupacion"<<endl;
            string occupation;
            cin>>occupation;

            cout<<"Compañia"<<endl;
            string company;
            cin>>company;

            //Create and add the new attendee
            Attendee attendee(typeAttendee,name,occupation,company);
            listEvent[option].addAttendee(attendee);

        }
        //The data from the event list where the new registered attendees are already registered is written in the txt
        writeTxt(listEvent);

        break;
    }
    
    case 3:{

        cout<<"Seleccione el evento del cual quiere ver la lista de asistentes:"<<endl;

        for (size_t i = 0; i < listEvent.size(); i++)
    {
        cout<<i<<") "<<listEvent[i].getType()<<";"<<listEvent[i].geLocation()<<";"<<listEvent[i].getTopic()<<";"<<listEvent[i].getDuration()<<";"<<listEvent[i].getAttendees().size()<<endl;

    }
        int option;
        cin>>option;

    //error control in case of entering invalid data
    while (option>listEvent.size()-1 || option<0)
    {
        cout<<"Error, ingrese una opcion valida"<<endl;
        for (size_t i = 0; i < listEvent.size(); i++)
        {
        cout<<i<<") "<<listEvent[i].getType()<<";"<<listEvent[i].geLocation()<<";"<<listEvent[i].getTopic()<<";"<<listEvent[i].getDuration()<<";"<<listEvent[i].getAttendees().size()<<endl;

        }
        cin>>option;
    }

        vector<Attendee> attendeers = listEvent[option].getAttendees();
        //iterates by the number of attendees who go to the event
        for (size_t j = 0; j < listEvent[option].getAttendees().size(); j++)
        {
            
            cout<<attendeers[j].getTypeAttendee()<<"-"<<attendeers[j].getName()<<"-"<<attendeers[j].getOccupation()<<"-"<<attendeers[j].getCompany()<<endl;
            
        }
    }

    default:
        break;
    }

};

void menu(vector<Event>& listEvent) {
    
    cout<< "---Seleccione la accion que desea realizar---"<<endl;
    cout<< "1) Creacion de un nuevo evento"<<endl;
    cout<< "2) Registrar asistentes a un evento"<<endl;
    cout<< "3) Ver la lista de asistentes"<<endl;
    cout<< "4) Mostrar un informe"<<endl;

    int option;
    cin>>option;
    //error control in case of entering invalid data
    while (option!=1 && option!=2 && option!=3 && option!=4)
    {
        cout<<"Es distinto de 0"<<endl;
        cout<< "---Error, Seleccione una opcion valida---"<<endl;
    cout<< "1) Creacion de un nuevo evento"<<endl;
    cout<< "2) Registrar asistentes a un evento"<<endl;
    cout<< "3) Ver la lista de asistentes"<<endl;
    cout<< "4) Mostrar un informe"<<endl;
        cin>>option;
    }
    
    options(listEvent,option);

    cout<<"Desea realizar otra accion?"<<endl;
    cout<<"1) Para si"<<endl;
    cout<<"2) No"<<endl;
    cin>>option;
    
    if (option == 1)
    {
        menu(listEvent);
    }
    
    cout<<"Fin del programa"<<endl;
    
}
